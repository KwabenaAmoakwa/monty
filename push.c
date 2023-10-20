#include "monty.h"

/**
 * push - add node to the stack
 * @head: stack head
 * @line: line_number
 * Return: no return
*/
void push(stack_t **head, unsigned int line)
{
	stack_t *newnode = NULL;
	(void)line;

	if ((strcmp("0", gv) != 0  && atoi(gv) == 0) || gv == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	newnode = (stack_t *)malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (*head == NULL)
	{
		newnode->next = NULL;
		newnode->n = atoi(gv);
		newnode->prev = NULL;
		*head = newnode;
	}
	else
	{
		newnode->n = atoi(gv);
		newnode->next = (*head);
		newnode->prev = NULL;
		(*head) = newnode;
	}
}
