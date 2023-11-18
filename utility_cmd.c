#include "shell_ver_three.h"

/**
 * construct_full_command - concatenate to /bin/
 * @path: /bin/ path
 * @command: command to add
 * Return: full command
 */
char *construct_full_command(const char *path, const char *command)
{
	char *full_command = malloc(strlen(path) + strlen(command) + 1);

	if (full_command == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	strcpy(full_command, path);
	strcat(full_command, command);

	return (full_command);
}
