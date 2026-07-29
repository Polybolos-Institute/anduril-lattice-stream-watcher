#include "anduril_lattice_rest/client.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

namespace {

const char* EnvOrEmpty(const char* key) {
  const char* v = std::getenv(key);
  return v ? v : "";
}

std::string ExtractField(const std::string& json, const char* key) {
  const std::string pat = std::string("\"") + key + "\":\"";
  const auto p = json.find(pat);
  if (p == std::string::npos) {
    return {};
  }
  std::size_t i = p + pat.size();
  std::string s;
  while (i < json.size() && json[i] != '"') {
    if (json[i] == '\\' && i + 1 < json.size()) {
      s.push_back(json[i + 1]);
      i += 2;
      continue;
    }
    s.push_back(json[i]);
    ++i;
  }
  return s;
}

}  // namespace

int main(int argc, char** argv) {
  double seconds = 30.0;
  bool auth_only = false;
  for (int i = 1; i < argc; ++i) {
    const std::string a = argv[i];
    if (a == "--auth-only") {
      auth_only = true;
    } else if (a == "--seconds" && i + 1 < argc) {
      seconds = std::atof(argv[++i]);
    } else if (a == "--help" || a == "-h") {
      std::cerr
          << "anduril_lattice_stream_watcher - read-only Lattice entity SSE\n"
          << "  --auth-only\n"
          << "  --seconds N   (default 30)\n"
          << "Env: LATTICE_ENDPOINT CLIENT_ID CLIENT_SECRET ENV_TOKEN\n";
      return 0;
    }
  }

  anduril_lattice_rest::Client client;
  client.SetEndpoint(EnvOrEmpty("LATTICE_ENDPOINT"));
  client.SetCredentials(EnvOrEmpty("LATTICE_CLIENT_ID"),
                        EnvOrEmpty("LATTICE_CLIENT_SECRET"),
                        EnvOrEmpty("LATTICE_ENV_TOKEN"));
  const auto missing = client.MissingConfig();
  if (!missing.empty()) {
    std::cerr << "[watcher] missing env:";
    for (const auto& m : missing) {
      std::cerr << " " << m;
    }
    std::cerr << "\n";
    return 1;
  }

  if (!client.FetchToken()) {
    std::cerr << "[watcher] OAuth FAILED\n";
    return 1;
  }
  std::cerr << "[watcher] OAuth OK endpoint=" << client.EndpointHost() << "\n";
  if (auth_only) {
    return 0;
  }

  int count = 0;
  const bool ok = client.StreamEntities(seconds, [&](const std::string& data) {
    ++count;
    const std::string id = ExtractField(data, "entityId");
    const std::string name = ExtractField(data, "name");
    std::cerr << "[watcher] event#" << count
              << " entityId=" << (id.empty() ? "?" : id)
              << " name=" << (name.empty() ? "-" : name)
              << " bytes=" << data.size() << "\n";
    return true;
  });

  if (!ok) {
    std::cerr << "[watcher] stream FAILED\n";
    return 1;
  }
  std::cerr << "[watcher] done events=" << count << " seconds=" << seconds
            << "\n";
  return 0;
}
