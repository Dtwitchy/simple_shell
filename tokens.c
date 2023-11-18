#include "shell_ver_three.h"

/**
 * tokenizer - tokenize the input command.
 * @input: the input command.
 * Return: array of tokens.
 */
char **tokenizer(char *input)
{
	char **tokens = malloc(10 * sizeof(char *));
	char *token;
	int token_count = 0;

	if (tokens == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " ");
	while (token != NULL)
	{
		tokens[token_count++] = strdup(token);
		if (tokens[token_count - 1] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " ");
	}

	tokens[token_count] = NULL;

	return (tokens);
}
