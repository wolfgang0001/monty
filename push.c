#include "monty.h"

/**
 * push - adding a new node to the stack or a queue
 * @stack: head of the stack
 * @line_number: the file's line
 * Return: nothing
*/

void push(stack_t **stack, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(*stack);
			fclose(bus.file);
			free(bus.line);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		fclose(bus.file);
		free(bus.line);
		exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);

	if (bus.status == STACK)
		add_node(stack, n);
	else
		add_node_end(stack, n);
}
