# Bringing `cpropep` source to the current decade

## Disclaimer

All content is developed by the authors mentioned in the comments of the files.

```text
Antoine Lefebvre <antoine.lefebvre@polymtl.ca>
Mark Pinese <pinese@cyberwizards.com.au>
Geoff O'Callaghan <geoff@starbiz.com.au>
```

## Current compiled app list

- `cpropep`
- `prop`
- `lrd`
- `mcp`
- `analyser`
- `rockflight`

## Roadmap

- [x] Recover source code history from legacy CVS. See [RECOVERY.md](docs/RECOVERY.md).
- [x] Restructure project folder to compile with modern CMake.
- [x] Set up Github workflow for automatic compilation and release for Windows, Mac OS, Linux.
- [x] Implement my own `gpcp` since original dependency can't be found. See [lib/gpcp](lib/gpcp/).
- [x] Document tools usage instruction (minimal).
- [x] Document libraries logic and development (minimal).
- [x] Move static docs and example files from source folders into `docs/<app>/`.
- [x] Move local app source files to local include subdir or promote to lib, except endpoint.
- [x] Check if libs should be downgraded to local includes.
- [x] Add [`cgilib`](https://www.infodrom.org/projects/cgilib/) and `syslog` dependencies.
- [x] Make `cgilib` compatible with Windows by renaming `aux.c` and `aux.h` to `cgiaux.*`.
- [x] Compile em all. 
- [ ] Create regression tests with input files and expected outputs for known examples.

## Future

- [ ] Fork only `cpropep` logic into dedicated repository.
- [ ] Export `cpropep` libraries as bindings for Python, C++, Matlab or others needed, like [pypropep](https://github.com/jonnydyer/pypropep) for example into [mpropep](https://github.com/thrust-team/mpropep).
- [ ] Compare results with other tools like [nasa/cea](https://github.com/nasa/cea).
- [ ] Create regression tests based on examples from NASA RP-1311.
