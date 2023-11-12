#include "main.h"

/**
 * tokenizer - to tokenize input with or like strtok
 * @input: the input read from stdin with getline
 * Return: an array of arguments
 */
char **tokenizer(char *input)
{
	char *token, **token_array = malloc(MAX_NUM_ARGUMENTS * sizeof(char *));
	int i = 0;

	if (token_array == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	if (input[0] == '/')
	{
		token_array[i++] = strdup(input);
	}
	else
	{
		token = strtok(input, " \t\n");

		while (token != NULL)
		{
			token_array[i] = strdup(token);
			if (token_array[i] == NULL)
			{
				perror("strdup");
				exit(EXIT_FAILURE);
			}
			i++;

			/* If more than 64 arguments, print error, then next token */
			if (i >= MAX_NUM_ARGUMENTS - 1)
			{
				fprintf(stderr, "Too many arguments\n");
				exit(EXIT_FAILURE);
			}

			token = strtok(NULL, " \t\n");
		}
	}
	token_array[i] = NULL; /* NULL-terminate */
	return (token_array);
}
