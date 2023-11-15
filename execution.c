#include "shell_version_two.h"

/**
 * execute - execute shell commands.
 * @command: the command to execute.
 * @arguments: array of arguments for the command
 * @envp: array of environment variables
 * Return: success or failure code
 */
int execute(char *command, char *arguments[], char *envp[])
{
	pid_t new_process;
	int status;

	new_process = fork();

	if (new_process == 0)
	{
		if (execve(command, arguments, envp) == -1)
		{
			fprintf(stderr, "./hsh: %s: command not found\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else if (new_process < 0)
		perror("fork");
	else
	{
		waitpid(new_process, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));

		return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}
