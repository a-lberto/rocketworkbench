# libcompat

Portability layer for cross-platform compatibility (GCC, MSVC, Borland).

## Features

- **String Functions**: Mapping of `strcasecmp` and `strncasecmp`.
- **Math Macros**: Standard `__min` and `__max`.
- **Boolean Type**: `bool`, `true`, and `false` definitions for C.
- **CLI Options**: `getopt` implementation for Windows.

## Usage

Include `compat.h` to use standard POSIX-like names on all platforms.
