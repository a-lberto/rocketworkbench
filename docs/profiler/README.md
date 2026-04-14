# apps/profiler

Rocket mass and inertia profiling tool.

## Features

- Calculates Center of Gravity (CG), mass, and moments of inertia (Ix, Iy).
- Profiles rocket components: body tubes, fins, motors, tanks, and nose cones.
- Uses a hierarchical configuration file to define the rocket assembly.

## Usage

```bash
profiler -f rocket.conf
```

Requires a configuration file defining the rocket geometry and material properties.
