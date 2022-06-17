#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

glob_t glob;

/**
 * run - Execute an opcode
 * @stack: Pointer to list
 * @line_number: Line number
 *
 */
void run(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instructions[] = {{"push", push_s}, {"pop", pop},
					{"pall", pall}, {"pint", pint},
					{"nop", nop}, {NULL, NULL}};

	glob.line_copy = strdup(glob.line);
	if (glob.line_copy[0] == '\0' || strcmp(glob.line_copy, "nop") == 0
	    || glob.line_copy[0] == '#')
	{
		free(glob.line_copy);
		return;
	}

	glob.line_copy = strtok(glob.line_copy, DELIMS);
	if (strcmp(glob.line_copy, "queue") == 0)
	{
		instructions[0].f = push_q;
		free(glob.line_copy);
		return;
	}
	if (strcmp(glob.line_copy, "stack") == 0)
	{
		instructions[0].f = push_s;
		free(glob.line_copy);
		return;
	}

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, glob.line_copy) == 0)
		{
			instructions[i].f(stack, line_number);
			free(glob.line_copy);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, glob.line_copy);
	free(glob.line_copy);
	exit(EXIT_FAILURE);
}
