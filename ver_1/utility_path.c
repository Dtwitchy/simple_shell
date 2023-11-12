#include "main.h"
#include <stdlib.h>

/**
 * find_path - find the full path of a command in PATH
 * @command: the command to search for
 * Return: the full path or NULL if not found
 */
char *find_path(char *command)
{
	char *path_to_env, *path, *token, *full_path;

	path_to_env = getenv("PATH");
	if (path_to_env == NULL)
	{
		perror("getenv");
		return (NULL);
	}

	path = strdup(path_to_env);
	if (path == NULL)
	{
		perror("strdup");
		return (NULL);
	}

	printf("PATH: %s\n", getenv("PATH"));
	token = strtok(path, ":");
	while (token != NULL)
	{
		printf("Trying path: %s\n", full_path);
		full_path = build_path(token, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

/**
 * build_path - build the full path of a command
 * @directory: the directory to append
 * @command: the command
 * Return: the full path
 */
char *build_path(char *directory, char *command)
{
	size_t len = strlen(directory) + strlen(command) + 2;
	char *full_path = malloc(len);

	if (full_path == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	snprintf(full_path, len, "%s/%s", directory, command);
	return (full_path);
}
