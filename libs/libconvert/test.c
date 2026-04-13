
#include <stdio.h>

#include "convert.h"

int main(void)
{

  double val = 1.0;
  double new;
  
  if (!convert(&val, "lb", "kg", &new))
    printf("Converted value: %f\n", new);
  else
    printf("Abort.\n");
  return 0;
  
}
