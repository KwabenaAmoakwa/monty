#include "monty.h"
char *gv;

/**
* run_operations - stores a string from standard input into a buffer
* @stack: head linked list
* @line: line number of instruction
* @toks: tokenized instruction
* Return: On success 1.
* On error, exit.
*/
void run_operations(stack_t **stack, char **toks, int line)
{
	int i, num_opcodes;
	instruction_t opcd[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"add", add},
		{"sub", sub},
		{"pop", pop},
		{"mul", mul},
		{"div", _div},
		{"mul", mul},
		{"pchar", pchar},
		{"mod", mod},
		{"pstr", pstr}
	};
	num_opcodes = sizeof(opcd) / sizeof(opcd[0]);
	if (toks[0] == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, toks[0]);
		exit(EXIT_FAILURE);
	}
	if (toks[1] != NULL)
		gv = toks[1];
	for (i = 0; i < num_opcodes; i++)
	{
		if (strcmp(toks[0], opcd[i].opcode) == 0)
		{
			opcd[i].f(stack, line);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instructions %s\n", line, toks[0]);
	exit(EXIT_FAILURE);
}

/**
 * pall - prints the stack
 * @head: stack head
 * @line_number: no used
 * Return: no return
*/
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	if (*head == NULL)
	{
		printf("Stack underflow\n");
	}
	temp = *head;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
* free_stack - frees the stack
* @head: pointer to the top of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
