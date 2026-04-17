
#include <stdio.h>
#include <gba/grain.h>

int output_matlab(point_t *h, char *filename, int id)
{
  FILE *fd;
  char header[32];
  point_t *ptr;

  ptr = h;

  snprintf(header, sizeof(header), "S%d = [\n", id);
  fd = fopen(filename, "w");
  fprintf(fd, "%s", header);

  do
  {
    fprintf(fd, "% .15f, % .15f\n", ptr->x, ptr->y);
    ptr = ptr->next;
  } while (ptr != h);
  
  fprintf(fd, "% .15f, % .15f\n", ptr->x, ptr->y);
  
  fprintf(fd, "];\n");

  fclose(fd);
  return 0;
}

