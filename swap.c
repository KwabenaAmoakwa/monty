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

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	(*head)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *head;
	temp->next = *head;
	(*head)->prev = temp;
	temp->prev = NULL;
	*head = temp;
}
