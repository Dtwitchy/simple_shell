#include "main.h"

/**
 * execute - to execute the commands recieved as input
 * @tokenized_command: the array of arguments
 * @arguments: the arguments included
 * Return: 0 for success or -1 for fail
 */
int execute(char *tokenized_command, char **arguments)
{
	pid_t new_process;
	int status;
	char *full_path = find_path(tokenized_command);

	if (full_path != NULL)
	{
		new_process = fork();

		if (new_process == 0)
		{
			if (execve(full_path, arguments, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else if (new_process < 0)
		{
			perror("fork");
			free(full_path);
			return (-1);
		}
		else
		{
			waitpid(new_process, &status, WUNTRACED);
			free(full_path);
		}
	}
	else
	{
		fprintf(stderr, "Command '%s' not found\n", tokenized_command);
		return (-1);
	}

	return (0);
}
