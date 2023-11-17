#include "shell_version_two.h"

/**
 * execute - execute shell commands.
 * @command: the command to execute.
 * @arguments: array of arguments for the command
 * @envp: the environment variables
 * Return: success or failure code
 */
int execute(char *command, char *arguments[], char *envp[])
{
	char *path = "/bin";
	char *full_command = malloc(strlen(command) + strlen(path) + 2);
	int result;

	if (command[0] != '/' && access(command, X_OK) == -1)
	{
		if (full_command == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		strcpy(full_command, path);
		strcat(full_command, "/");
		strcat(full_command, command);

		result = process(full_command, arguments, envp, 1);
		free(full_command);
		return (result);
	}
	else
	{
		result = process(command, arguments, envp, 0);
		return (result);
	}
}

/**
 * process - create a process and execute the command.
 * @command: the command to execute.
 * @arguments: array of arguments for the command
 * @envp: the environment variables
 * @prepend: flag indicating whether /bin/ was prepended to the command
 * Return: success or failure code
 */
int process(char *command, char *arguments[], char *envp[], int prepend)
{
	pid_t new_process;
	int status;

	new_process = fork();

	if (new_process == 0)
	{
		if (execve(command, arguments, envp) == -1)
		{
			if (prepend)
				fprintf(stderr, "./hsh: 1: %s: not found\n", command + 5);
			else
				fprintf(stderr, "./hsh: 1: %s: not found\n", command);
			exit(127);
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
