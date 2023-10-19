#include "monty.h"
/**
* main - Main entry point
* @argc: head linked list
* @argv: line number of instruction
* Return: On success 1.
*/
int main(int argc, char **argv)
{
	char *buffer = NULL, **args = NULL, **toks = NULL;
	int i;
	stack_t *stack = NULL;
	size_t buff_len = 0;
	FILE *fp;
	ssize_t num_rd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((num_rd = getline(&buffer, &buff_len, fp)) != -1)
	{
		args = split_input(buffer);
		if (args == NULL)
		{
			free(args);
			exit(EXIT_FAILURE);
		}
		for (i = 0; args[i] != NULL; i++)
		{
			toks = tokenize(args[i]);
			run_operations(&stack, toks, i + 1, buffer, args);
		}
	}
	free(buffer);
	my_free(args);
	free_stack(stack);
	return (0);
}
