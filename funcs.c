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

/**
 * rotl - rotates the stack to the top
 * @stack: Stack
 * @line_number: Line number
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp, *new;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	new = (*stack)->next;
	new->prev = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	(*stack)->next = NULL;
	(*stack)->prev = tmp;
	(*stack) = new;
}

/**
 * rotr - Rotate right, bottom element becomes first
 * @stack: Stack
 * @line_number: Line number
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
