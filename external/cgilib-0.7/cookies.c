/*
    cookies.c - Cookie support for CGI library
    Copyright (C) 1999,2007,8 by Martin Schulze <joey@infodrom.org>
     
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cgi.h>
#include "cgiaux.h"

s_cookie **cgiReadCookies()
{
    char *http_cookie;
    char *curpos, *n0, *n1, *v0, *v1, *cp;
    s_cookie **res, *pivot = NULL;
    int count;
    int len;

    if ((curpos = http_cookie = getenv ("HTTP_COOKIE")) == NULL)
	return NULL;
    count = 0;
    if ((res = (s_cookie **)malloc (sizeof (s_cookie *))) == NULL)
	return NULL;
    res[0] = NULL;

    while (*curpos) {
	for (n0=curpos; *n0 && *n0==' '; n0++);
	for (n1=n0; *n1 && *n1!=' ' && *n1!='=' && *n1!=';' && *n1!=',';n1++);
	for (v0=n1; *v0 && (*v0==' ' || *v0=='=' || *v0==' ');v0++);
	if (*v0 == '"') {
	    v1=++v0;
	    for (;*v1 && *v1!='"';v1++);
	} else {
	    v1=v0;
	    for (;*v1 && *v1!=',' && *v1!=';';v1++);
	}

	if (n0 != n1) {
	    if (*n0 == '$') {
		if (strncasecmp (n0, "$version", 8) && strncasecmp (n0, "$path", 5)
		    && strncasecmp (n0, "$domain", 7)) {
		    curpos = v1+1;
		    continue;
		}
	    } else
		if (pivot && pivot->name) {
		    count++;
		    if ((res = (s_cookie **)realloc (res, sizeof (s_cookie *) * (count+1))) == NULL)
			return NULL;
		    res[count-1] = pivot;
		    res[count] = pivot = NULL;
		}

	    if (!pivot) {
		if ((pivot = (s_cookie *)malloc (sizeof (s_cookie))) == NULL)
		    return res;
		memset (pivot, 0, sizeof (s_cookie));
		if (res && res[0] && res[0]->version)
		    pivot->version = res[0]->version;	/* Warning: *Never* free() res[n!=0]->version */
	    }
            if (*n0 == '$') {
		n0++;
		len = sizeof (char) * (v1-v0);
		if ((cp = (char *)malloc (len)) == NULL)
		    return res;
		memset (cp, 0, len);
		strncpy (cp, v0, v1-v0);

		if (!strncasecmp (n0, "version", 7))
		    pivot->version = cp;
		else if (!strncasecmp (n0, "path", 4))
		    pivot->path = cp;
		else if (!strncasecmp (n0, "domain", 6))
		    pivot->domain = cp;
		else
		    free (cp);
	    } else {
		len = sizeof (char) * (n1-n0+1);
		if ((pivot->name = (char *)malloc (len)) == NULL)
		    return res;
		memset (pivot->name, 0, len);
		strncpy (pivot->name, n0, n1-n0);

		if (*v0 == '"')
		    v0++;
		len = sizeof (char) * (v1-v0+1);
		if ((pivot->value = (char *)malloc (len)) == NULL)
		    return res;
		memset (pivot->value, 0, len);
		strncpy (pivot->value, v0, v1-v0);
	    }
	} else {
	    curpos = n0+1;
	}
	curpos = v1;
	if (*curpos) curpos++;
    }

    count++;
    if ((res = (s_cookie **)realloc (res, sizeof (s_cookie *) * (count+1))) == NULL)
	return NULL;
    res[count-1] = pivot;
    res[count] = NULL;

    return res;
}

s_cookie *cgiGetCookie (s_cgi *parms, const char *name)
{
    int i;

    if (!parms || !parms->cookies)
	return NULL;
    for (i=0;parms->cookies[i]; i++)
	if (parms->cookies[i]->name && parms->cookies[i]->value && !strcmp(name,parms->cookies[i]->name)) {
	    cgiDebugOutput (1, "%s found as %s\n", name, parms->cookies[i]->value);
	    return parms->cookies[i];
	}
    cgiDebugOutput (1, "%s not found\n", name);
    return NULL;
}

char **cgiGetCookies (s_cgi *parms)
{
    int i, k;
    char **res = NULL;
    int len;

    if (!parms || !parms->cookies)
	return NULL;
    for (i=k=0;parms->cookies[i];i++)
	if (parms->cookies[i]->name && parms->cookies[i]->value)
	    k++;
    len = sizeof (char *) * ++k;
    if ((res = (char **)malloc (len)) == NULL)
	return NULL;
    memset (res, 0, len);
    for (i=k=0;parms->cookies[i]; i++) {
	if (parms->cookies[i]->name && parms->cookies[i]->value) {
	    len = strlen (parms->cookies[i]->name) +1;
	    if ((res[i] = (char *)malloc (len)) == NULL)
		return NULL;
	    memset (res[i], 0, len);
	    strcpy (res[i], parms->cookies[i]->name);
	}
    }
    return res;
}

/*
 * Local variables:
 *  c-indent-level: 4
 *  c-basic-offset: 4
 *  tab-width: 8
 * End:
 */
