# RocketWorkbench Libraries

Core libraries for thermochemical equilibrium, rocket motor design, and flight simulation.

## Core Libraries

- [**libcpropep**](./cpropep): The heart of the project. Implements the NASA RP-1311 algorithm for complex chemical equilibrium and rocket performance.
- [**libnum**](./num): Numerical methods for linear algebra (LU), root finding (Newton), and ODE integration (RK4).
- [**libgpcp**](./gpcp): General Purpose Configuration Parser. A hierarchical configuration library used to parse application-specific settings (e.g., rocket stages, motor parameters).

## Utilities

- [**libcompat**](./compat): Portability layer for cross-platform support (GCC, MSVC).
- [**libconvert**](./convert): Unit conversion utilities.
- [**libcgi**](./cgi): Common Gateway Interface utilities for web tools.
