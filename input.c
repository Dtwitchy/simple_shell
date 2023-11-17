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
	size_t i = 0, j;
	int c;
	char *temp;

	if (*lineptr == NULL || *n == 0)
	{
		*n = 4;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			perror("malloc");
			return (-1);
		}
	}

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (i == *n - 1)
		{
			*n *= 2;
			temp = (char *)malloc(*n);

			if (temp == NULL)
			{
				perror("malloc");
				free(*lineptr);
				return (-1);
			}
			for (j = 0; j < i; ++j)
				temp[j] = (*lineptr)[j];
			free(*lineptr);
			*lineptr = temp;
		}
		(*lineptr)[i++] = (char)c;
	}
	(*lineptr)[i] = '\0';
	if (c == EOF && i == 0)
		return (-1);
	return (i);
}
