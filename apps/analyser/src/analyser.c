#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/* Numerical method library */
#include <num/num.h>
/* Config file parser library */
#include <gpcp/gpcp.h>
/* Conversion library */
#include <convert/convert.h>

#include <getopt.h>

#include <analyser/analyser.h>

#define MAX_LINE 100

Options analyser_options[] = {
  {"datafile",        STRING,  NULL},
  {"format",          PARENT,  NULL},
  {"column",          INTEGER, "format"},
  {"time",            PARENT,  "format"},
  {"col",             INTEGER, "time"},
  {"units",           STRING,  "time"},
  {"thrust",          PARENT,  "format"},
  {"col",             INTEGER, "thrust"},
  {"units",           STRING,  "thrust"},
  {"comments",        STRING,  "format"},
  {"motor",           PARENT,  NULL},
  {"propellant_mass", PARENT,  "motor"},
  {"val",             FLOAT,   "propellant_mass"},
  {"units",           STRING,  "propellant_mass"},
  {"total_mass",      PARENT,  "motor"},
  {"val",             FLOAT,   "total_mass"},
  {"units",           STRING,  "total_mass"},
  {NULL,              0,       NULL}
};
        
int main(int argc, char *argv[])
{
  int n, c;
  
  char *datafile;      /* Name of the datafile */
  double *data = NULL; /* Array containing the data read in the data file */

  format_t format;
  motor_t   motor;
  results_t results;
  
  /* Name of the config file */
  char filename[FILENAME_MAX] = "\0";

  GPCP_RegisterOptions(analyser_options);
  
  /* Read the command line arguments */
  while (1)
  {
    c = getopt(argc, argv, "f:");
    if (c == EOF)
      break;
    switch (c)
    {
      case 'f':
          strncpy(filename, optarg, FILENAME_MAX);
          break;
    }
  }
  
  if (filename[0] =='\0')
  {
    printf("A config file must be specified.\n");
    return -1;
  }
  
  if (parse_config(filename, &datafile, &format, &motor))
    return 1;
  
  if (parse_datafile(datafile, &data, &n, &format))
    return 1;
  
  analyse_data(data, n, &results, &format, &motor);
  print_results(&results);  
  return 0;
}
