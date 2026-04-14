# apps/mcp

Motor Combustion Performance (MCP) simulator for solid rockets.

## Features

- Simulates internal ballistics of a solid rocket motor.
- Uses 4th-order Runge-Kutta integration to solve the pressure-time history.
- Integrates with `libcpropep` for propellant thermodynamic properties.

## Usage

Configuration is currently hardcoded in `test.c` for specific propellant combinations (e.g., AP/HTPB/Al).
