#include "monty.h"
/**
 * pchar_op - Prints the char at the top of the stack,
 * followed by a new line.
 * @top: Pointer to top element in stack
 * @line_number: Unsigned int representing line number
 * Return: Void
 */
void pchar_op(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	temp = *top;

	if (!temp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit_error(top);
	}

	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit_error(top);
	}

	printf("%c\n", temp->n);
}

/**
  *no_operation- No-operation function for Monty "nop" opcode
  *@top: Pointer to the top of the stack
  *@line_number: Unsigned int representing line_number
  *Return: Void
 */
void no_operation(stack_t **top, unsigned int line_number)
{
	(void) top; /*Parameter not used*/
	(void) line_number; /*Parameter not used*/
}

