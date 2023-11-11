#include "main.h"

/**
 * tokenizer - to tokenize input with or like strtok
 * @input: the input read from stdin with getline
 * Return: an array of arguments
 */
char **tokenizer(char *input)
{
	char *token;
	char **token_array = malloc(MAX_NUM_ARGUMENTS * sizeof(char *));
	int i = 0;

	/* Check if the token array was properly assigned required memory */
	if (token_array == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* Using strtok, we tokenize the input based on space, tabs and newlines */
	token = strtok(input, " \t\n");

	/* Duplicate the token we got */
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
	token_array[i] = NULL; /* NULL-terminate */
	return (token_array);
}
