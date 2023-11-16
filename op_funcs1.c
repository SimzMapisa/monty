#include "monty.h"

/**
 * push - Inserts an element onto a stack
 * @stack: Stack pointer
 * @n: The data or integer value to push onto the stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *nu_nod = malloc(sizeof(stack_t));
	(void)line_number; /*Parameter not used*/

	if (nu_nod == NULL)
	{
		perror("Error: Memory allocation failed\n");
		exit_error(stack);
	}

	nu_nod->n = atoi(global_context.arg);
	nu_nod->prev = NULL;
	nu_nod->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = nu_nod;
	}

	*stack = nu_nod;
}

/**
 * pall - Traverses and displays all values in the stack
 * @stack: A pointer to a pointer to the top of the stack
 * @line_number: Unsigned int representing line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * swap - Swaps top two elements of the stack.
 * @top: Pointer to the top element of stack
 * @line_number: unsigned int representing line number
 * Return: Void
 */
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *top_element;
	int len = 0, temp;

	for (top_element = *top; top_element; top_element = top_element->next)
	{
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit_error(top);
	}

	top_element = *top;
	temp = top_element->n;
	top_element->n = top_element->next->n;
	top_element->next->n = temp;
}

/**
 * pint - Prints element on top in the stack
 * @stack: Pointer to the stack
 * @line_number: Line number
 */
void print(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL)
        {
                freopen(NULL, "w", stdout);
                fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
                exit(EXIT_FAILURE);
        }

        printf("%d\n", (*stack)->n);
}


/**
 * pop - Removes top element in a stack
 * @stack: Pointer to the stack
 *@ line_number: unsigned int representing the line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_element = *stack;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit_error(stack);
	}

	*stack = (*stack)->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(top_element);
}

