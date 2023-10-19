#include "monty.h"

/**
* split_input - Tokenizes a string and returns
* a dynamically allocated array of strings
* @s: Buffer entered by user
* Return: Double pointer of the string
*/
char **split_input(char *s)
{
	char **toks = NULL;
	int num = 0;
	char *token = NULL, *delimiter = "\n";

	toks = malloc(sizeof(char *) * 25);
	if (toks == NULL)
		return (NULL);

	token = strtok(s, delimiter);

	while (token != NULL)
	{
		toks[num] = token;
		token = strtok(NULL, delimiter);
		num++;
	}

	toks[num] = NULL;
	return (toks);
}

/**
* tokenize - Tokenizes a string and returns
* a dynamically allocated array of strings
* @s: Buffer entered by user
* Return: Double pointer of the string
*/
char **tokenize(char *s)
{
	char **toks = NULL;
	int num = 0;
	char *token = NULL, *delimiter = " \t\n";

	toks = malloc(sizeof(char *) * 25);
	if (toks == NULL)
		return (NULL);

	token = strtok(s, delimiter);

	while (token != NULL)
	{
		if (num >= 25)
		{
			toks = realloc(toks, sizeof(char *) * (num + 10));
			if (toks == NULL)
			{
				return (NULL);
			}
		}
		toks[num] = token;
		token = strtok(NULL, delimiter);
		num++;
	}

	toks[num] = NULL;
	return (toks);
}
