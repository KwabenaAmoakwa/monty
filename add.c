#include "monty.h"
/**
 * add - print the stack as string
 * @head: head of the stack
 * @line_number: line number
 * Return: no return
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;

	temp->next->n = temp->n + temp->next->n;

	*head = (*head)->next;
	free(temp);
}
