#include "monty.h"

/* cmdContext global_context; */

/**
 * open_monty_file - Function to open monty file
 *@filename: File to be opened
 * Return: The file
 */

FILE *open_monty_file(const char *filename)
{
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (file);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	FILE *monty_file;
	char *input;
	size_t size = 0;
	ssize_t get_input = 1;
	unsigned int counter = 0;

	if (argc != 2)
	{
		usage_err();
	}
	monty_file = open_monty_file(argv[1]);
	global_context.monty_file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (get_input > 0)
	{
		input = NULL;
		get_input = getline(&input, &size, monty_file);
		global_context.input = input;
		counter++;
		if (get_input > 0)
		{
			op_exec(input, &stack, counter, monty_file);
		}
		free(input);
	}
	free_mem(stack);
	fclose(monty_file);
	return (0);
}
