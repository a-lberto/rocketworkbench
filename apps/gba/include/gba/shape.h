#ifndef shape_h
#define shape_h

#include "grain.h"

int build_triangular(point_t *h, int nb_point, double c);
int build_nuclear(point_t *h, int nb_point, double r1, double r2, int n);
int build_rectangular(point_t *h, int nb_point, double width, double height);
int build_cross(point_t *h, int nb_point, double width, double height);
int build_round(point_t *h, int nb_point, double r);

#endif

