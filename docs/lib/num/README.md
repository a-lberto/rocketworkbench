# libnum

Numerical methods library providing algorithms for linear algebra, root finding, integration, and differential equations.

## Features

### Linear Algebra

- **LU Decomposition**: Solve systems of linear equations using LU factorization with column pivoting.
- **Matrix Operations**: Utilities for printing matrices and vectors.

```c
#include "num.h"
// Matrix is stored in column-major order: matrix[row + col * num_rows]
int NUM_lu(double *matrix, double *solution, int neq);
```

### Root Finding

- **Newton's Method**: Find roots using a function and its derivative.
- **Secant Method**: Find roots using two initial guesses.
- **Fixed Point Iteration**: Solve `x = f(x)`.
- **System Newton**: Solve systems of non-linear equations using a Jacobian.

```c
int NUM_newton(double (*f)(double), double (*df)(double), double x0, int nmax, double eps, double *ans);
int NUM_sysnewton(func_t *Jac, func_t *R, double *x, int nvar, int nmax, double eps);
```

### Ordinary Differential Equations (ODE)

- **Runge-Kutta 4th Order (RK4)**: Fixed-step integration for systems of ODEs.
- **Runge-Kutta-Fehlberg (RKF)**: Adaptive-step integration.

### Integration & Interpolation

- **Trapezoidal Rule**: Numerical integration.
- **Simpson's Rule**: Numerical integration.
- **Cubic Splines**: Creation and evaluation of cubic spline interpolants.

## Usage

Refer to `test_num.c` for comprehensive examples of each numerical method.

## Matrix Representation

Matrices should be allocated as a flat 1D array of `double`:
`matrix = (double *) malloc(sizeof(double) * rows * cols);`

Accessing element `(row, col)`:
`matrix[row + col * num_rows]`
