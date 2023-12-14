#include "monty.h"
#include "stdio.h"
/**
 * add_node - adding node to the head stack
 * @stack: head of the stack
 * @n: file's line
 * Return: nothing
*/
void add_node(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
