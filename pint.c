#include "monty.h"
/**
* pint - t the stack as string
* @head: head of the stack
* @line_number: line number
* Return: no return
*/
void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
