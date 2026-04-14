# libthermo

Library to load and compute thermodynamic properties of chemical species and propellants.

## Files

- `thermo.c`, `thermo.h`: Core thermodynamic calculations (enthalpy, entropy, specific heat, Gibbs free energy).
- `load.c`, `load.h`: Loaders for `thermo.dat` and `propellant.dat` data files.

## Usage

### Load Data Files

Initialize the library by loading the required data files into global lists.

```c
#include "load.h"

int main() {
    if (load_thermo("data/thermo.dat") < 0) {
        return 1; // Handle error
    }
    if (load_propellant("data/propellant.dat") < 0) {
        return 1; // Handle error
    }
    // ...
    return 0;
}
```

### Search Species

Find the index of a species or propellant by name or formula.

```c
#include "thermo.h"

int sp = thermo_search("CO2");
int prop = propellant_search("ALUMINUM");
```

### Compute Properties

Compute properties for a specific species at a given temperature `T` (Kelvin).

```c
double h = enthalpy_0(sp, 3000.0);    // Dimensionless Ho/RT
double s = entropy_0(sp, 3000.0);     // Dimensionless So/R
double cp = specific_heat_0(sp, 3000.0); // Dimensionless Cp/R
```
