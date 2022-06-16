#include "monty.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

glob_t glob;

/**
 * main - Run monty code
 * @argc: Arguments count
 * @argv: Command-line arguments
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	int fd;
	stack_t *head;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		write(2, "Usage: monty file\n", 18);
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Cannot open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	head = NULL;
	while (1)
	{
		glob.line = readline(fd);
		line_number++;

		if (glob.line == NULL)
		{
			free(glob.line);
			break;
		}
		else
		{
			run(&head, line_number);
			free(glob.line);
		}
	}
	free_list(head);
	close(fd);

	return (0);
}
