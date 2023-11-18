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
