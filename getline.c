#include "monty.h"
#include <fcntl.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NCHAR 64

void strstrip(char *s);
char *trim(char *str);
/**
 * _getline - read one line until EOF
 * @fd: input
 * @buffer: pointer to output in memory
 *
 * Return: string
 */
char *_getline(int fd, char **buffer)
{
	int r;
	char ch;
	char *new;
	char *tmp;
	size_t buflen = 0, nchar = NCHAR;

	new = malloc(nchar);
	if (!new)
	{
		perror("Error:");
		return (NULL);
	}

	while (1)
	{
		r = read(fd, &ch, sizeof(ch));
		if (!(r > 0))
		{
			free(new);
			return NULL;
		}

		if (ch == '\n')
			break;

		new[buflen++] = ch;

		if (buflen + 1 >= nchar)
		{
			tmp = realloc(new, nchar * 2);
			if (!tmp)
			{
				perror("Error:");
				new[buflen] = 0;
				return new;
			}
			new = tmp;
			nchar *= 2;
		}
	}
	new[buflen] = 0;

	if (buflen == 0)
	{
		new[0] = '\n';
		new[1] = '\0';
	}
	trim(new);
	*buffer = new;
	return *buffer;
}

char *trim(char *str)
{
	size_t len = 0;
	char *frontp = str;
	char *endp = NULL;

	if( str == NULL ) { return NULL; }
	if( str[0] == '\0' ) { return str; }

	len = strlen(str);
	endp = str + len;

	/* Move the front and back pointers to address the first non-whitespace
	 * characters from each end.
	 */
	while( isspace((unsigned char) *frontp) ) { ++frontp; }
	if( endp != frontp )
	{
		while( isspace((unsigned char) *(--endp)) && endp != frontp ) {}
	}

	if( frontp != str && endp == frontp )
		*str = '\0';
	else if( str + len - 1 != endp )
		*(endp + 1) = '\0';

	/* Shift the string so that it starts at str so that if it's dynamically
	 * allocated, we can still free it on the returned pointer.  Note the reuse
	 * of endp to mean the front of the string buffer now.
	 */
	endp = str;
	if( frontp != str )
	{
		while( *frontp ) { *endp++ = *frontp++; }
		*endp = '\0';
	}

	return str;
}
