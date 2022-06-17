#include "monty.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
					{"nop", nop}, {"sub", sub},
					{"add", add}, {"mul", mul},
					{"mod", mod}, {"pchar", pchar},
					{"pstr", pstr}, {"swap", swap},
					{NULL, NULL}};

	if (glob.line[0] == '\0' || strcmp(glob.line, "nop") == 0
	    || glob.line[0] == '#')
	{
		free(glob.line);
		return;
	}

	glob.line = strtok(glob.line, DELIMS);
	if (strcmp(glob.line, "queue") == 0)
	{
		instructions[0].f = push_q;
		free(glob.line);
		return;
	}
	if (strcmp(glob.line, "stack") == 0)
	{
		instructions[0].f = push_s;
		free(glob.line);
		return;
	}

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, glob.line) == 0)
		{
			instructions[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, glob.line);
	free(glob.line);
	exit(EXIT_FAILURE);
}
