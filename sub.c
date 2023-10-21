#include "monty.h"
/**
 * sub - print the stack as string
 * @head: head of the stack
 * @line_number: line number
 * Return: no return
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	unsigned int sub;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	sub = temp->next->n - temp->n;
	temp->next->n = sub;
	*head = temp->next;
	free(temp);
}

/**
 * _div - print the stack as string
 * @head: head of the stack
 * @line_number: line number
 * Return: no return
 */
void _div(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n = temp->next->n / temp->n;
	*head = (*head)->next;
	free(temp);
}

/**
 * mul - print the stack as string
 * @head: head of the stack
 * @line_number: line number
 * Return: no return
 */
void mul(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int prd;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	prd = temp->n * temp->next->n;
	temp->next->n = prd;
	*head = temp->next;
	free(temp);
}

/**
 * mod - print the stack as string
 * @head: head of the stack
 * @line_number: line number
 * Return: no return
 */
void mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp->next->n = temp->next->n % temp->n;
	*head = (*head)->next;
	free(temp);
}

/**
 * pchar - print the stack as string
 * @head: head of the stack
 * @line_number: line number
 * Return: no return
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n > 127 || (*head)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
