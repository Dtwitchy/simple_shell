#include "shell_version_two.h"

/**
 * input - my own getline
 * @lineptr: the line to read into
 * @n: the size of the file
 * @stream: where to read from
 * Return: as it should
 */
ssize_t input(char **lineptr, size_t *n, FILE *stream)
{
	size_t i = 0;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = BUFFER;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			perror("malloc");
			return (-1);
		}
	}

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		(*lineptr)[i++] = (char)c;
	}
	(*lineptr)[i] = '\0';

	if (c == EOF && i == 0)
		return (-1);

	return (i);
}
