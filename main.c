#include "monty.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
 * main - Run monty code
 * @argc: Arguments count
 * @argv: Command-line arguments
 *
 * Return - Always 0
 */
int main(int argc, char **argv)
{
	int fd;
	char *line;
	char *ptr;

	if (argc != 1)
	{
		write(2, "Usage: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	fd = open("numbers.txt", O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while(1)
	{
		ptr = _getline(fd, &line);
		if(ptr == NULL)
		{
			free(ptr);
			break;
		}
		else if (ptr[0] == '\0')
		{
			free(ptr);
			continue;
		}
		else
		{
			printf("%s %d\n", line, line[0]);
			free(ptr);
		}
	}
	close(fd);
	return 0;
}
