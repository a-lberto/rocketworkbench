# liblrd

Liquid Rocket Design (LRD) library.

## Features

- Calculate motor characteristics (mass flow rate, areas, diameters, volumes).
- Design parameters for chambers and nozzles.
- Handling of liquid propellant O/F ratios.

## Data Structures

- `design_param_t`: Input design criteria (Pc, thrust, L*, etc.).
- `motor_t`: Calculated dimensions and volumes.
- `liquid_propellant_t`: Oxidizer/Fuel configuration.

## Usage

Used to dimension a liquid rocket engine based on performance results from `lib/cpropep`.
