# libcpropep

Core library for calculating complex chemical equilibrium compositions and rocket performance. It implements the algorithm from NASA RP-1311 (Gordon and McBride).

## Files

- `equilibrium.c`, `equilibrium.h`: Main equilibrium solver.
- `performance.c`, `performance.h`: Rocket performance calculations (Isp, C*, Cf, etc.).
- `type.h`: Core data structures (`equilibrium_t`, `composition_t`, `product_t`).
- `derivative.c`, `derivative.h`: Thermodynamic derivatives calculation.
- `print.c`, `print.h`: Output formatting.

## Usage

### Initialization

The `equilibrium_t` structure holds all state and composition data.

```c
#include "equilibrium.h"

equilibrium_t equil;
initialize_equilibrium(&equil);
```

### Define Propellant

Add propellant components by their index in the global propellant list (loaded via `libthermo`).

```c
// Add 100g of Aluminum (index 5)
add_in_propellant(&equil, 5, GRAM_TO_MOL(100.0, 5));
```

### Solve Equilibrium

Set the state and solve for the specified problem type (e.g., `TP` for fixed Temperature and Pressure).

```c
set_state(&equil, 3000.0, 68.04); // 3000K, 68.04 atm
equilibrium(&equil, TP);
compute_thermo_properties(&equil);
```

### Rocket Performance

Compute performance for frozen or shifting equilibrium.

```c
#include "performance.h"

// Shifting equilibrium performance
shifting_performance(&equil, PRESSURE, 1.0); // Exit at 1 atm
```

## Data Structures

- `equilibrium_t`: Master structure containing propellant, products, and computed properties.
- `equilib_prop_t`: Calculated thermodynamic properties (H, S, Cp, gamma, etc.).
- `performance_prop_t`: Rocket parameters (Isp, C*, Cf, area ratio).

## Dependencies

- `libthermo`: For species data and base thermodynamic properties.
- `libnum`: For solving the underlying linear systems (LU decomposition).
