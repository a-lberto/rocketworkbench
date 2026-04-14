# apps/analyser

Thrust data analysis tool for rocket motors.

## Features

- Parses configuration files (`.conf`) and raw data files.
- Computes:
  - Total and average thrust.
  - Burn time.
  - Specific impulse (Isp) and exhaust velocity.
  - Propellant mass fraction.
  - Impulse-to-weight ratio.

## Usage

```bash
analyser -f test.conf
```

Requires a configuration file specifying data format and motor properties.
