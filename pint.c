#include "monty.h"
/**
* pstr - print the stack as string
* @head: head of the stack
* @line_number: line number
* Return: no return
*/
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_number);
	}
	temp = *head;

	printf("%d\n", temp->n);
}
