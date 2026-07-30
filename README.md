# anduril-lattice-stream-watcher

Read-only **Anduril Lattice** entity stream watcher (Windows / WinHTTP SSE).

Connects with sandbox OAuth, opens `POST /api/v1/entities/stream`, and logs
entity events. No publish. No tasking. No C2 / ROE.

Built by [Polybolos Institute](https://www.polybolos.org).
**Independent sample - not an Anduril product.**

## Build

Needs sibling [anduril-lattice-rest-winhttp](https://github.com/Polybolos-Institute/anduril-lattice-rest-winhttp)
(or FetchContent from GitHub).

```powershell
cd cpp
cmake -B build -A x64
cmake --build build --config Release
```

## Run

```powershell
# load LATTICE_* then:
.\cpp\build\Release\anduril_lattice_stream_watcher.exe --auth-only
.\cpp\build\Release\anduril_lattice_stream_watcher.exe --seconds 30
```

## Related doors

- [anduril-lattice-rest-winhttp](https://github.com/Polybolos-Institute/anduril-lattice-rest-winhttp)
- [anduril-lattice-sandbox-dx](https://github.com/Polybolos-Institute/anduril-lattice-sandbox-dx)


## License

MIT - see [LICENSE](LICENSE).

## Contact

Polybolos Institute builds integrated C2 systems for contested operations.

For production deployment, integration guidance, and commercial licensing:

mark.brown@polybolos.org · https://www.polybolos.org
