#include "shell_ver_three.h"

/**
 * tokenize_input - string and return an array of tokens
 * @input: the input string to tokenize
 * @delimiters: characters used as delimiters
 * Return: an array of tokens
 */
char **tokenize_input(char *input, const char *delimiters)
{
	char **tokens = NULL;
	size_t token_count = 0;
	char *token;

	for (token = strtok(input, delimiters);
			token != NULL;
			token = strtok(NULL, delimiters))
	{
		tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
		if (tokens == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}

		tokens[token_count] = strdup(token);
		if (tokens[token_count] == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}

		token_count++;
	}

	tokens = realloc(tokens, (token_count + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		perror("realloc");
		exit(EXIT_FAILURE);
	}

	tokens[token_count] = NULL;
	return (tokens);
}

/**
 * free_tokens - Free the memory allocated for an array of tokens
 * @tokens: the array of tokens to free
 */
void free_tokens(char **tokens)
{
	size_t i;

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);
	free(tokens);
}
