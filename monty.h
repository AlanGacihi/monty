#ifndef MONTY_H
#define MONTY_H

#define DELIMS " \t"

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_s - Structure for global variable.
 * @line: Result of getline on file.
 * @line_copy: Copy of line.
 */
typedef struct glob_s
{
	char *line;
	char *line_copy;
} glob_t;

extern glob_t glob;
extern char* strdup(const char*);

char *readline(int fd);
size_t stack_len(const stack_t *h);
void push_s(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void run(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void push_q(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void free_list(stack_t *head);

#endif /* MONTY_H */
