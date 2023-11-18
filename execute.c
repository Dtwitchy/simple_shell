#include "shell_ver_three.h"

/**
 * execute - to execute commands recieved
 * @command: the command recieved
 * @arguments: array of arguments for the command
 * @envp: the environment variables
 * Return: status information
 */
int execute(char *command, char *arguments[], char *envp[])
{
	int status;
	pid_t new = fork();

	if (new == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}
	if (new == 0)
	{
		if (execve(command, arguments, envp) == -1)
		{
			fprintf(stderr, "./hsh: 1: %s: not found\n", command);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(new, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));

		return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}
