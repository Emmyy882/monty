#include "monty.h"

/**
 * _push - push int to a stack stack_t
 * @stack: linked lists for monty stack
 * @line_num: number of line opcode occurs on
 */
void _push(stack_t **stack, unsigned int line_num)
{
	char *arg;
	int push_arg;

	push_arg = 0;
	arg = strtok(NULL, "\n\t ");
	if (arg != NULL && isnumber(arg) == 1)
	{
		push_arg = atoi(arg);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		error_exit(stack);
	}

	if (sq_flag == 1)
	{
		add_dnodeint_end(stack, push_arg);
	}

	if (sq_flag == 0)
	{
		add_dnodeint(stack, push_arg);
	}

}

/**
 * _pall - print all the values on the stack
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 */
void _pall(stack_t **stack, __attribute__ ((unused))unsigned int line_num)
{
	stack_t *runner;

	runner = *stack;
	while (runner != NULL)
	{
		printf("%d\n", runner->n);
		runner = runner->next;
	}
}

/**
 * _pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 *
 */
void _pint(stack_t **stack, unsigned int line_num)
{
	stack_t *runner;

	runner = *stack;
	if (runner == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		
		error_exit(stack);
	}
	printf("%d\n", runner->n);
}

/**
 * _swap - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 *
 */
void _swap(stack_t **stack, unsigned int line_num)
{
	stack_t *runner;
	int tmp;

	runner = *stack;
	if (runner == NULL || runner->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		
		error_exit(stack);
	}
	
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}

/**
 * _pop - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_num: number of line opcode occurs on
 */
void _pop(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		error_exit(stack);
	}
	
	delete_dnodeint_at_index(stack, 0);
}
