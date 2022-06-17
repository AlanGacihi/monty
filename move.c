#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

glob_t glob;

int number(stack_t *head, char *s, unsigned int line_number);

/**
 * push_s - Adds an element at the top of a stack
 * @stack: Pointer to stack.
 * @line_number: Line number.
 */
void push_s(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *new;

	n = number(*stack, strtok(NULL, DELIMS), line_number);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(glob.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = *stack;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * push_q - Adds an element to a queue.
 * @stack: Pointer to queue.
 * @line_number: Line number
 */
void push_q(stack_t **stack, unsigned int line_number)
{
	int n;
	stack_t *new;
	stack_t *tmp;

	tmp = *stack;
	n = number(*stack, strtok(NULL, DELIMS), line_number);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(glob.line);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;
	if (!*stack)
	{
		new->prev = *stack;
		*stack = new;
		return;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

/**
 * pop - Removes an element from a stack
 * @stack: Pointer to stack
 * @line_number: Line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *iterator = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free(glob.line);
		exit(EXIT_FAILURE);
	}

	*stack = iterator->next;
	if (iterator->next)
		iterator->next->prev = NULL;
	free(iterator);
}

/**
 * number - Turns a string into an integer.
 * @head: Pointer to stack.
 * @s: String to be converted.
 * @line_number: Line number.
 *
 * Return: Converted integer
 */
int number(stack_t *head, char *s, unsigned int line_number)
{
	char *endptr;
	long int var;

	if (s == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(glob.line);
		free_list(head);
		exit(EXIT_FAILURE);
	}

	var = strtol(s, &endptr, 10);

	if (*endptr || strlen(endptr) == strlen(s))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(glob.line);
		free_list(head);
		exit(EXIT_FAILURE);
	}

	return (var);
}

/**
 * swap - Swap the top two element of the stack
 * @stack: Pointer to the head of the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free(glob.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;
	temp = second->n;
	second->n = first->n;
	first->n = temp;
}
