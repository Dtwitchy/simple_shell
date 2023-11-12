#include "shell_version_two.h"

/**
 * trim_whitespace - removes leading and trailing whitespace from a string
 * @str: the string to modify
 */
void trim_whitespace(char *str)
{
	size_t len = strlen(str);
	size_t start = 0;
	size_t end = len - 1;

	while (isspace((unsigned char)str[start]))
		start++;

	while (end > start && isspace((unsigned char)str[end]))
		end--;

	memmove(str, str + start, end - start + 1);
	str[end - start + 1] = '\0';
}

/**
 * remove_newline - removes newline character from the end of a string
 * @str: the string to modify
 */
void remove_newline(char *str)
{
	size_t len = strlen(str);

	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}
