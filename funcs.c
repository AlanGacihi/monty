#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_list - Frees a linked list.
 * @head: Pointer to the first node of the list.
 */
void free_list(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

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
 * nop - Does nothing"
 * @stack: Pointer to stack.
 * @line_number: Line number
 */
void nop(__attribute__((unused)) stack_t **stack,
	 __attribute__((unused)) unsigned int line_number)
{
}
