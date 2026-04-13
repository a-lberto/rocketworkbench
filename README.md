# Bringing `cpropep` source to the current decade

## Disclaimer

All content is developed by the authors mentioned in the comments of the files.

```text
Antoine Lefebvre <antoine.lefebvre@polymtl.ca>
Mark Pinese <pinese@cyberwizards.com.au>
Geoff O'Callaghan <geoff@starbiz.com.au>
```

## Goals

- [x] Recover source code history from legacy CVS. See [RECOVERY.md](docs/RECOVERY.md)
- [x] Restructure project folder to compile with modern CMake
- [x] Set up Github workflow for automatic compilation and release for Windows, Mac OS, Linux
- [ ] Create regression tests with input files and expected outputs for known examples.
- [ ] Find dependencies currently missing to compile remaining applications.
- [ ] Document tools usage instruction.
- [ ] Document libraries logic and development.
- [ ] Clean up git history with atomic, purposeful edits and methodology comments.

## Future

- [ ] Fork only `cpropep` logic into dedicated directory.
- [ ] Export `cpropep` libraries as bindings for Python, C++, Matlab or others needed, like [pypropep](https://github.com/jonnydyer/pypropep) for example into [mpropep](https://github.com/thrust-team/mpropep).
- [ ] Compare results with other tools like [nasa/cea](https://github.com/nasa/cea).
- [ ] Create regression tests based on examples from NASA RP-1311.
