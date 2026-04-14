# libconvert

Unit conversion utility.

## Features

- Convert values between different units (e.g., metric to imperial).
- Uses a central conversion engine.

## Usage

```c
#include "convert.h"

double val = 1.0;
double newval;
convert(&val, "m", "ft", &newval);
```
