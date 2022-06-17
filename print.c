#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * pall - prints all the elements of a list.
 * @stack: Head of the list.
 * @line_number: Line number.
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *h;

	h = *stack;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * pint - Print first element of a stack
 * @stack: Pointer to stack.
 * @line_number: Line number.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *h;

	h = *stack;
	if (h == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(glob.line_copy);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pchar - print char at top of stack
 * @stack: double pointer to top of stack
 * @line_number: Line number
 *
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int i;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free(glob.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;

	if (!(i >= 0 && i <= 127))
	{
		printf("L%u: can't pchar, value out of range", line_number);
		free(glob.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", i);
}

/**
 * pstr - prints out string starting from top of stack
 * @stack: double pointer to top of stack
 * @line_number: Line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL)
	{
		if (isascii(tmp->n) && tmp->n != 0)
			putchar(tmp->n);
		else
			break;
		tmp = tmp->next;
	}
	putchar('\n');
}
