# lib/mcp

Motor Combustion Performance (MCP) library for solid rockets.

## Features

- Propellant burning rate calculations using the Saint-Robert (Vieille) law: `r = aP^n`.
- Motor geometry representation for internal ballistics simulation.

## Data Structures

- `motor_t`: Burning rate coefficients and nozzle geometry.
- `data_t`: Integration structure for burning area and chamber volume functions.
