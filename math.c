#include "monty.h"

/**
 * add - Adds top two elements in a stack.
 * @stack: Pointer to the top element of the stack
 * @line_number: Line number
 * Return: No return
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;
	int len = 0, sum;

	while (top)
	{
		top = top->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit_error(stack);
	}

	top = *stack;
	sum = top->n + top->next->n;
	top->next->n = sum;
	*stack = top->next;
	free(top);
}

/**
 * sub - Opcode Subtraction
 * @top: Pointer to top of stack
 * @line_number: unsigned int representing line number
 * Return: Void
 */
void sub(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	int result, nodes;

	temp = *top;

	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit_error(top);
	}

	temp = *top;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*top = temp->next;
	free(temp);
}

/**
 * div_op - Division of top two elements in a stack.
 * @top: Pointer to top element in stack
 * @line_number: Unsigned int representing Line number
 * Return: Void
 */
void div_op(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	int nodes, result;

	temp = *top;

	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit_error(top);
	}

	temp = *top;

	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit_error(top);
	}

	result = temp->next->n / temp->n;
	temp->next->n = result;
	*top = temp->next;
	free(temp);
}

/**
 * mul - Multiplies the top two elements of the stack.
 * @top: Pointer to top of Stack
 * @line_number: Unsigned int representing Line number
 * Return: Void
 */
void mul(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	int nodes, result;

	temp = *top;

	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit_error(top);
	}

	temp = *top;

	result = temp->next->n * temp->n;
	temp->next->n = result;
	*top = temp->next;
	free(temp);
}

/**
 * mod - calculates the modulus
 * @top: Pointer to top of Stack
 * @line_number: Unsigned int representing line number
 * Return: Void
 */
void mod(stack_t **top, unsigned int line_number)
{
	stack_t *temp;
	int nodes, result;

	temp = *top;

	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;

	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit_error(top);
	}

	temp = *top;

	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit_error(top);
	}

	result = temp->next->n % temp->n;
	temp->next->n = result;
	*top = temp->next;
	free(temp);
}

