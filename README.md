# Bringing `cpropep` source to the current decade

## Disclaimer

All content is developed by the authors mentioned in the comments of the files.

```text
Antoine Lefebvre <antoine.lefebvre@polymtl.ca>
Mark Pinese <pinese@cyberwizards.com.au>
Geoff O'Callaghan <geoff@starbiz.com.au>
```

## Project Structure

```text
rocketworkbench\
├───apps\                       # Applications and specific tool logic
│   ├───analyser\               # Post-test thrust-time data analysis
│   ├───cpropep\                # Main thermochemical equilibrium CLI (NASA RP-1311)
│   ├───gba\                    # Grain Burn Analysis (2D cross-section regression)
│   ├───grainanalysis\          # Star grain geometry generation tools
│   ├───lrd\                    # Liquid Rocket Design and dimensioning
│   ├───mcp\                    # Solid Motor Combustion Performance (internal ballistics)
│   ├───profiler\               # Mass, CG, and inertia profiling for rocket assemblies
│   ├───prop\                   # Interactive shell for thermodynamic properties
│   ├───rocket\                 # Propellant configuration parsing sample
│   ├───rockflight\             # Flight trajectory simulation (ballistics/6-DOF)
│   └───simulator\              # Advanced C++ extensible flight simulator
├───lib\                        # Core reusable libraries
│   ├───compat\                 # Portability layer (cross-platform support)
│   ├───convert\                # Unit conversion utilities
│   ├───cpropep\                # Equilibrium and performance engine (includes libthermo)
│   ├───gpcp\                   # General Purpose Configuration Parser (hierarchical)
│   └───num\                    # Numerical methods (linear algebra, ODE, root finding)
├───docs\                       # Documentation and examples
│   ├───apps\                   # Application-specific manuals and examples
│   ├───lib\                    # Library API documentation and logic
│   └───data\                   # Reference data and thermochemical property docs
├───data\                       # Default thermochemical and propellant databases
├───external\                   # Third-party dependencies (cgilib, syslog-win)
└───scripts\                    # Build and packaging automation (PowerShell)
```

## Current compiled app list

- `cpropep` / `cpropep-web`
- `prop`
- `lrd` / `lrd-web`
- `mcp` / `mcp-test`
- `analyser`
- `rockflight` / `viewer`
- `profiler`
- `gba`
- `grainanalysis`
- `rocket`
- `simulator`

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
- [x] Compile 'em all locally.
- [x] Compile 'em all with CI/CD.
- [x] Organize docs.
- [ ] Test tools with their expected inputs or outputs, document results.
- [ ] Create regression tests with input files and expected outputs for known examples.

## Future

- [ ] Fork only `cpropep` logic into dedicated repository.
- [ ] Export `cpropep` libraries as bindings for Python, C++, Matlab or others needed, like [pypropep](https://github.com/jonnydyer/pypropep) for example into [mpropep](https://github.com/thrust-team/mpropep).
- [ ] Compare results with other tools like [nasa/cea](https://github.com/nasa/cea).
- [ ] Create regression tests based on examples from NASA RP-1311.
