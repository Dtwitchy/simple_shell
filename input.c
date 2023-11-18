#include "shell_ver_three.h"

/**
 * input - the custom getline function
 * @lineptr: the line to read into
 * @size: the size of the input
 * @stream: where to read input from
 * Return: 0 for success
 */
ssize_t input(char **lineptr, size_t *size, FILE *stream)
{
	size_t i = 0;
	int ASCII;

	if (!lineptr || !size || !stream)
		return (-1); /* Invalid input parameters */

	/* Allocate initial buffer if needed */
	if (*lineptr == NULL)
	{
		*lineptr = malloc(sizeof(char *) * BUFFER);
		if (*lineptr == NULL)
			return (-1);
		*size = BUFFER;
	}

	/* Read until we enounter a newline or EOF */
	while ((ASCII = getc(stream)) != EOF && ASCII != '\n')
	{
		if (i >= *size - 1) /* Resizing the BUFFER as needed */
		{
			*size *= 2; /* Multiply current BUFFER by two */
			*lineptr = realloc(*lineptr, *size);
			if (*lineptr == NULL)
				return (-1);
		}
		(*lineptr)[i++] = (char)ASCII; /* Convert ASCII to char */
	}
	(*lineptr)[i] = '\0';
	return (i);
}
