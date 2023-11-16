#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>
#define OP_DELIM " \n\t"

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
 * struct cmdContext - Represents context for a Monty command
 * @arg: Value of the command argument
 * @monty_file: Pointer to the Monty file
 * @input: input of the current line
 * @stk_or_Q: Flag indicating stack or queue
 *
 * Description: Carries values needed for processing Monty commands.
 */
typedef struct cmdContext
{
	char *arg;
	FILE *monty_file;
	char *input;
	int stk_or_Q;
} cmdContext;

extern cmdContext global_context;

int op_exec(char *input, stack_t **stack, unsigned int lineNum, FILE *file);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **, unsigned int line_number);
void print(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void no_operation(stack_t **top, unsigned int line_number);
void free_mem(stack_t *top);
void exit_error();
FILE *open_monty_file(const char *filename);
void usage_err();
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **top, unsigned int line_number);
void div_op(stack_t **top, unsigned int line_number);
void mul(stack_t **top, unsigned int line_number);
void mod(stack_t **top, unsigned int line_number);
void pchar_op(stack_t **top, unsigned int line_number);

#endif

