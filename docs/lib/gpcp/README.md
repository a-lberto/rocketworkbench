# GPCP - General Purpose Configuration Parser

GPCP is a C library designed to parse hierarchical configuration files. It provides a simple API to navigate nested structures and retrieve values with basic type checking.

## Configuration File Format

Configuration files parsed by GPCP use a simple key-value assignment syntax with support for hierarchical nesting and comments.

### Syntax Rules

- **Assignments**: `key = value`
- **Nesting**: `section = ( key1 = value1, key2 = value2 )`
- **Lists**: Multiple sections can have the same key (e.g., `stage = (...)`).
- **Strings**: Can be quoted (e.g., `name = "My Rocket"`) or unquoted if they don't contain special characters.
- **Separators**: Assignments can be separated by commas or newlines.
- **Comments**: Any text following a `#` is ignored until the end of the line.

### Example: `test.conf`

```config
datafile = "test2.txt"
format = (
    column = 2,
    time   = (col = 1, units = "s"),
    thrust = (col = 2, units = "lbf"),
    comments = "#"
)

motor = (
    propellant_mass = (val = 117., units = "g"),
    total_mass      = (val = 200., units = "g")
)
```

### Example: `sample.sim`

```config
simulation = (
    initial_conditions = (
        u = 400.0,
        v = 0.0,
        altitude = 1000.0
    ),
    rocket = (
        stage = (
            dry_mass = 10.0,
            engine = (
                type = "constant_thrust",
                thrust = 1000.0
            )
        )
    )
)
```

---

## Data File Format

While GPCP parses the *structure* of a configuration, many applications use it to point to external data files (e.g., `datafile = "test2.txt"`). These data files are typically raw column-based ASCII files.

### Example: `test2.txt`

```text
# time (s) thrust (lbf)
0       4
0.01    9.6
0.02    14
# ... more data ...
```

---

## Building a Parser with GPCP

Integrating GPCP into your application involves four main steps.

### 1. Define Option Types

Define an array of `Options` to map keys to their expected types. This allows GPCP to handle type conversion automatically.

```c
#include <gpcp/gpcp.h>

Options my_options[] = {
    {"datafile", STRING,  NULL},
    {"format",   PARENT,  NULL},
    {"column",   INTEGER, "format"},
    {"time",     PARENT,  "format"},
    {"col",      INTEGER, "time"},
    {"units",    STRING,  "time"},
    {NULL,       0,       NULL} // Sentinel
};
```

### 2. Register and Read

Register the options and read the file into a `Data` structure.

```c
Data *config;
GPCP_RegisterOptions(my_options);

if (GPCP_ReadFile("my_config.conf", &config) != 0) {
    fprintf(stderr, "Error reading config file.\n");
    return 1;
}
```

### 3. Navigate and Extract

Use `GPCP_EnterLevel` to dive into nested sections and `GPCP_GetValue` to retrieve values.

```c
char *datafile;
int columns;

// Get value at root level
if (GPCP_GetValue("datafile", &datafile) == 0) {
    printf("Loading data from: %s\n", datafile);
}

// Enter 'format' level
if (GPCP_EnterLevel("format", 0) == 0) {
    GPCP_GetValue("column", &columns);
    
    // Enter nested 'time' level
    if (GPCP_EnterLevel("time", 0) == 0) {
        int time_col;
        GPCP_GetValue("col", &time_col);
        GPCP_ExitLevel(); // Back to 'format'
    }
    
    GPCP_ExitLevel(); // Back to root
}
```

### 4. Handling Lists (Multiple Parents)

If a configuration has multiple sections with the same name (like `stage` in a rocket simulation), use `GPCP_NumParent` to count them and loop through them.

```c
int num_stages = GPCP_NumParent("stage");
for (int i = 0; i < num_stages; i++) {
    GPCP_EnterLevel("stage", i);
    // Process stage details...
    GPCP_ExitLevel();
}
```

### 5. Cleanup

Always free the data structure when finished.

```c
GPCP_FreeData(&config);
```

---

## Implementation Reference

For real-world examples in this codebase, refer to:

- **`apps/analyser/analyser.c`**: Demonstrates deep nesting for motor and propellant data.
- **`apps/profiler/parser.c`**: Shows how to handle units and rocket body parts (ogive nose, tubes, etc.).
- **`lib/gpcp/test.c`**: A minimal test suite showing basic usage.
