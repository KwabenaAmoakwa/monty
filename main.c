#include "monty.h"
/**
* main - Main entry point
* @argc: head linked list
* @argv: line number of instruction
* Return: On success 1.
*/
int main(int argc, char **argv)
{
	char *buffer = NULL, **toks = NULL;
	int line = 1;
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
		if (buffer && buffer[0] == '#')
			continue;
		toks = tokenize(buffer);
		if (toks == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line, toks[0]);
			free(buffer);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		run_operations(&stack, toks, line);
		line++;
		free(toks);
	}
	fclose(fp);
	free(buffer);
	free_stack(stack);
	return (0);
}
