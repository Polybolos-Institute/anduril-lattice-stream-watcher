# anduril-lattice-stream-watcher

## Status & recognition (factual)

> Independent Polybolos Institute sample (not an Anduril product).  
> OASW(SO/LIC) Jul 2026 **Selected** (technically meritorious; under evaluation/consideration).  
> 1BCT/82nd Airborne Operation Epic Fury challenge (GoColosseum): **Submitted**.  
> AFRL Apr 2026: RQ portfolio share (Col Rondeau) + Control Science Center exchange (Weintraub; "state of the art" / partnership / SBIR language in correspondence). Attributed dialogue.  
> TRL 5 Decision-C2 lineage · Lattice sandbox / interop sample · Inquiries: mark.brown@polybolos.org · CAGE 1AVY9 · UEI RUSHH9B2UQV3

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

This repository is the open foundation (MIT).

Polybolos Institute also maintains a proprietary catalog of additional capabilities that are not published here. Contact us to discuss production deployment and commercial licensing.

mark.brown@polybolos.org · https://www.polybolos.org
