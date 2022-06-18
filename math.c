#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

glob_t glob;

/**
 * add - Calculates the sum of the top 2 elements on stack or queue.
 * @stack: Stack.
 * @line_number: Line number.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack ||!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(glob.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - Calculates the substraction of the top 2 elements on stack or queue.
 * @stack: Stack.
 * @line_number: Line number.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!stack ||!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free(glob.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * divv - Calculates the division of the top 2 elements on stack or queue.
 * @stack: Stack.
 * @line_number: Line number.
 */
void divv(stack_t **stack, unsigned int line_number)
{
	if (!stack ||!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free(glob.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(glob.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - Calculates the multiplication of the top 2 elements on stack or queue.
 * @stack: Stack.
 * @line_number: Line number.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!stack ||!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free(glob.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mod - Calculates the modulus of the top 2 elements on stack or queue.
 * @stack: Stack.
 * @line_number: Line number.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!stack ||!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free(glob.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free(glob.line);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
