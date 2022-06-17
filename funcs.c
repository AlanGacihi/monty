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
 * nop - Does nothing.
 * @stack: Pointer to stack.
 * @line_number: Line number
 */
void nop(__attribute__((unused)) stack_t **stack,
	 __attribute__((unused)) unsigned int line_number)
{
}
