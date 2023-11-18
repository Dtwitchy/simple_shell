#include "shell_ver_three.h"

/**
 * main - start of shell version three
 * Return: 0 for success and exit status
 */
int main(void)
{
	char **arguments, *read_input = NULL;
	ssize_t read_result;
	size_t len = 0, status = 0, i = 0;

	while (ONLINE)
	{
		fflush(stdout);
		read_result = input(&read_input, &len, stdin);
		if (read_result == -1)
		{
			if (feof(stdin))
				break;
			perror("getline");
			break;
		}
		remove_newline(read_input);
		trim_whitespace(read_input);
		arguments = tokenize_input(read_input, " \t\n");
		if (strcmp(read_input, "exit") == 0)
		{
			free(read_input);
			return (0);
		}
		status = execute(arguments[0], arguments, environ);
		if (status == 127)
			return (127);
		for (i = 0; arguments[i] != NULL; i++)
			free(arguments[i]);
		free(arguments);
	}
	free(read_input);
	return (0);
}
