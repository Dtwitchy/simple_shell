#include "main.h"

/**
 * prompt - display prompt
 * Return: void as in none
 */
void prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

/**
 * main - start of the shell
 * Return: 0 for success
 */
int main(void)
{
	char *read_into_from_input;
	char **tokenized_command;
	int i = 0;

	while (ONLINE)
	{
		prompt();
		if (input(&read_into_from_input) == -1)
		{
			/* Check for EOF and CTRL+D */
			if (errno == EOF)
				break;

			perror("getline");
			break;
		}

		if (strcmp(read_into_from_input, "exit") == 0)
			break;

		tokenized_command = tokenizer(read_into_from_input);

		if (execute(tokenized_command[0], tokenized_command) == -1)
			perror("execve");

		free(read_into_from_input);
		for (i = 0; tokenized_command[i] != NULL; i++)
			free(tokenized_command[i]);

		free(tokenized_command);
	}

	return (0);
}
