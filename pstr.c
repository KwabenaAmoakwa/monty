#include "monty.h"
/**
* pstr - print the stack as string
* @head: head of the stack
* @line_number: line number
* Return: no return
*/
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (*head == NULL)
	{
		printf("\n");
	}
	temp = *head;
	while (temp)
	{
		if (temp->n > 127 || temp->n <= 0)
		{
			break;
		}
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
