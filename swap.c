#include "monty.h"
/**
 * swap - print the stack as string
 * @head: head of the stack
 * @line_number: line number
 * Return: no return
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int v, count = 0;

	temp = *head;

	while (temp)
	{
		temp = temp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	v = temp->n;
	temp->n = temp->next->n;
	temp->next->n = v;
}
