cmake_minimum_required(VERSION 3.21)
project(anduril_lattice_stream_watcher VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT WIN32)
  message(FATAL_ERROR "WinHTTP only (Windows).")
endif()

set(_LIB "${CMAKE_CURRENT_SOURCE_DIR}/../../anduril-lattice-rest-winhttp")
if(EXISTS "${_LIB}/CMakeLists.txt")
  add_subdirectory("${_LIB}" alrw_build)
else()
  include(FetchContent)
  FetchContent_Declare(
    anduril_lattice_rest_winhttp
    GIT_REPOSITORY https://github.com/Polybolos-Institute/anduril-lattice-rest-winhttp.git
    GIT_TAG main
  )
  FetchContent_MakeAvailable(anduril_lattice_rest_winhttp)
endif()

add_executable(anduril_lattice_stream_watcher src/main.cpp)
target_link_libraries(anduril_lattice_stream_watcher PRIVATE anduril_lattice_rest::anduril_lattice_rest)
if(MSVC)
  target_compile_options(anduril_lattice_stream_watcher PRIVATE /W4 /permissive-)
endif()
