
#ifndef performance_h
#define performance_h

#include <compat.h>
#include <cpropep/return.h>

#include <cpropep/equilibrium.h>
#include <cpropep/derivative.h>


int frozen_performance(equilibrium_t *e, exit_condition_t exit_type,
                       double value);
int shifting_performance(equilibrium_t *e, exit_condition_t exit_type,
                         double value);

#endif

