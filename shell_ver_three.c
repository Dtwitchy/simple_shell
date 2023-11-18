#include "shell_ver_three.h"

/**
 * main - start of the shell
 * Return: 0 for success
 */
int main(void)
{
	char *read_input = NULL, **arguments;
	ssize_t getline_result;
	size_t len = 0;
	int i, multiline = 0, cmd_status = 0;

	while (ONLINE)
	{
		if (!multiline)
			fflush(stdout);
		getline_result = getline(&read_input, &len, stdin);
		if (getline_result == -1)
		{
			if (feof(stdin))
				break;
			perror("getline");
			break;
		}
		remove_newline(read_input);
		trim_whitespace(read_input);
		if (read_input[0] == '\0')
			multiline = 1;
		else
			multiline = 0;
		arguments = tokenizer(read_input);
		if (builtin_exit(read_input, arguments, cmd_status))
		{
			free(read_input);
			return (cmd_status);
		}
		cmd_status = execute(arguments[0], arguments, environ);
		if (cmd_status == 127)
			return (127);
		for (i = 0; arguments[i] != NULL; i++)
			free(arguments[i]);
		free(arguments);
	}
	free(read_input);
	return (0);
}
