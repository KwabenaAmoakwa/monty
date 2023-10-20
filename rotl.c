#include "monty.h"
/**
* rotl- rotates the stack to the top
* @head: stack head
* @counter: line_number
* Return: no return
*/
void rotl(stack_t **head, unsigned int counter)
{
	stack_t *temp, *val;
	(void)counter;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	temp = *head;
	val = (*head)->next;
	val->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = val;
}
