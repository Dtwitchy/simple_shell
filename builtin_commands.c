#include "shell_ver_three.h"

/**
 * builtin_exit - handle builtin exit command
 * @command: the command to consider
 * @arguments: use argument as exit if given
 * @cmd_status: as name implies
 * Return: 1 for builtin and 0 otherwise
 */
int builtin_exit(char *command, char *arguments[], int cmd_status)
{
	int i;

	if (strcmp(command, "exit") == 0)
	{
		if (arguments && arguments[1])
		{
			for (i = 0; arguments[1][i]; i++)
			{
				if (!isdigit(arguments[1][i]))
				{
					fprintf(stderr, "./hsh: 1: %s: Illegal number: %s\n",
							command, arguments[1]);
					exit(2);
				}
			}

			exit(atoi(arguments[1]));
		}
		else
		{
			exit(cmd_status);
		}
	}
	return (0);
}


/**
 * builtin_env - handle builtin env command
 * @command: the command
 * @environ: the env input
 * Return: 0 for builtin
 */
int builtin_env(char *command, char **environ)
{
	int i;

	if (strcmp(command, "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
		return (1);
	}

	return (0);
}

/**
 * handle_var - checks and executes built-in commands.
 * @command: the command.
 * @arguments: flipping not.
 * @cmd_status: array of environment variables.
 * @pid: pid as said;
 * Return: void as in none
 */

int handle_var(char *command, char *arguments[], int cmd_status, int pid)
{
	int i;

	if (strcmp(command, "echo") == 0)
	{
		for (i = 1; arguments[i] != NULL; i++)
		{
			if (strcmp(arguments[i], "$?") == 0)
				printf("%d\n", cmd_status);
			else if (strcmp(arguments[i], "$$") == 0)
				printf("%d\n", pid);
			else
				printf("%s ", arguments[i]);
		}
		printf("\n");
		return (1);
	}
	return (0);
}
