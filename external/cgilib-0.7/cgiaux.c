/*
    aux.c - Auxilliary code for CGI library
    Copyright (C) 2007,8 by Martin Schulze <joey@infodrom.org>
     
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software Foundation
    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <syslog.h>

int cgiDebugLevel = 0;
int cgiDebugType = 1;

char *cgiEscape (char *string)
{
    char *cp, *np;
    char *buf;
    size_t len;

    for (cp=string, len=0; *cp; cp++) {
	switch (*cp) {
	case '&':
	    len+=5;
	    break;
	case '<':
	case '>':
	    len+=4;
	    break;
	default:
	    len++;
	    break;
	}
    }

    if (len == strlen(string))
	return strdup(string);

    if ((buf = (char *)malloc(len+1)) == NULL)
	return NULL;

    for (cp=string, np=buf; *cp; cp++) {
	switch (*cp) {
	case '&':
	    *np++ = '&';
	    *np++ = 'a';
	    *np++ = 'm';
	    *np++ = 'p';
	    *np++ = ';';
	    break;
	case '<':
	    *np++ = '&';
	    *np++ = 'l';
	    *np++ = 't';
	    *np++ = ';';
	    break;
	case '>':
	    *np++ = '&';
	    *np++ = 'g';
	    *np++ = 't';
	    *np++ = ';';
	    break;
	default:
	    *np++ = *cp;
	    break;
	}
    }
    *np = '\0';

    return buf;
}

void cgiDebugOutput (int level, char *format, ...)
{
  va_list args;

  if (level <= cgiDebugLevel) {

      va_start (args, format);

      switch (cgiDebugType) {
      case 0:
	  printf ("<pre>\n");
	  vprintf (format, args);
	  printf ("\n</pre>\n");
	  break;
      case 1:
	  vfprintf (stderr, format, args);
	  printf ("\n");
	  break;
      case 2:
	  vsyslog (LOG_DEBUG, format, args);
	  break;
      }

      va_end (args);
  }
}

#define BUFSIZE 128

char *cgiGetLine (FILE *stream)
{
    static char *line = NULL;
    static size_t size = 0;
    char buf[BUFSIZE];
    char *cp;

    if (!line) {
      if ((line = (char *)malloc (BUFSIZE)) == NULL)
	return NULL;
      size = BUFSIZE;
    }
    line[0] = '\0';

    while (!feof (stream)) {
      if ((cp = fgets (buf, sizeof (buf), stream)) == NULL)
	return NULL;

      if (strlen(line)+strlen(buf)+1 > size) {
	if ((cp = (char *)realloc (line, size + BUFSIZE)) == NULL)
	  return line;
	size += BUFSIZE;
	line = cp;
      }

      strcat (line, buf);
      if (line[strlen(line)-1] == '\n') {
	line[strlen(line)-1] = '\0';
	if (line[strlen(line)-1] == '\r')
	  line[strlen(line)-1] = '\0';
	cgiDebugOutput (4, "Read line '%s'", line);
	return line;
      }
    }

    return NULL;
}

/*
 * Local variables:
 *  c-indent-level: 4
 *  c-basic-offset: 4
 *  tab-width: 8
 * End:
 */
