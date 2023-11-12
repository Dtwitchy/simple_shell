#include "main.h"

/**
 * input - the function for getline
 * @input: the input recieved
 * Return: 0 for success, -1 fail
 */
int input(char **input)
{
	size_t initial_buffer_size = 0;
	ssize_t characters;

	/* Using builtin getline ~ custom later */
	characters = getline(input, &initial_buffer_size, stdin);

	/* Check if there was some error in reading the input */
	if (characters == -1)
	{
		perror("getline");
		return (-1);
	}

	/* if there is a newline character, change to NULL-termination */
	if ((*input)[characters - 1] == '\n')
		(*input)[characters - 1] = '\0';

	return (0);
}
