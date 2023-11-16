#include "monty.h"

/**
 * usage_err - Function to handle usage error
 */

void usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * op_exec - Executes the opcode commands
 * @stack: Pointer to top of stack
 * @lineNum: Line counter
 * @file: Monty file pointer
 * @input: opcode input
 * Return: Void
 */
int op_exec(char *input, stack_t **stack, unsigned int lineNum, FILE *file)
{
	unsigned int i;
	char *current_opcode;
	instruction_t op_dict[] = {
		{"push", push}, {"pall", pall},
		{"pint", print}, {"pop", pop},
		{"swap", swap}, {"nop", no_operation},
		{"add", add}, {"sub", sub},
		{"div", div_op}, {"mod", mod},
		{"pchar", pchar_op}, {NULL, NULL}
	};

	current_opcode = strtok(input, OP_DELIM);

	if (current_opcode && current_opcode[0] == '#')
		return (0);
	global_context.arg = strtok(NULL, OP_DELIM);

	for (i = 0; op_dict[i].opcode; i++)
	{
		if (strcmp(current_opcode, op_dict[i].opcode) == 0)
		{
			op_dict[i].f(stack, lineNum);
			return (0);
		}
	}

	if (current_opcode && op_dict[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, current_opcode);
		fclose(file);
		free(input);
		free_mem(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * exit_error - Handles cleanup and exits on failure
 * @stack: Pointer to the top of the stack
 * @file: Monty file pointer
 * @input: opcode input
 */
void exit_error(stack_t **stack, FILE *file, char *input)
{
	(void)file;
	(void)input;

	fclose(global_context.monty_file);
	free(global_context.input);
	free_mem(*stack);
	exit(EXIT_FAILURE);
}


/**
 * free_mem - Frees the stack
 * @top: Pointer to the head of the stack
 */
void free_mem(stack_t *top)
{
	stack_t *temp;

	temp = top;
	while (top)
	{
		temp = top->next;
		free(top);
		top = temp;
	}
}
