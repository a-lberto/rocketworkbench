# RocketWorkbench Libraries

Core libraries for thermochemical equilibrium, rocket motor design, and flight simulation.

## Core Libraries

- [**libthermo**](./thermo): Load and compute thermodynamic properties for chemical species and propellants.
- [**libnum**](./num): Numerical methods for linear algebra (LU), root finding (Newton), and ODE integration (RK4).
- [**libcpropep**](./cpropep): The heart of the project. Implements the NASA RP-1311 algorithm for complex chemical equilibrium and rocket performance.

## Design & Performance

- [**liblrd**](./lrd): Liquid Rocket Design. Dimensions liquid motors based on thermochemical results.
- [**libmcp**](./mcp): Motor Combustion Performance. Internal ballistics for solid rocket motors (Vieille's law).
- [**libgpcp**](./gpcp): Grain Performance calculation for solid motors.

## Simulation & Dynamics

- [**librockflight**](./rockflight): Flight dynamics, atmospheric models, and equations of motion for trajectory simulation.
- [**libsimulation**](./simulation): C++ framework for extensible rocket flight simulations.

## Utilities

- [**libcompat**](./compat): Portability layer for cross-platform support (GCC, MSVC).
- [**libconvert**](./convert): Unit conversion utilities.
