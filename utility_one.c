#include "shell_ver_three.h"

/**
 * resize - custom realloc function
 * @ptr: pointer to initial allocation
 * @size: the new size to allocate
 * Return: pointer to the new allocation
 */
char *resize(char *ptr, size_t size)
{
	char *new_ptr = (char *)malloc(size);

	if (new_ptr == NULL)
		return (NULL);
	strcpy(new_ptr, ptr);
	free(ptr);
	return (new_ptr);
}

/**
 * length - find the length of a string
 * @str: the string to count
 * Return: lenght of the string
 */
size_t length(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * trim_whitespace - removes leading and trailing whitespace from a string
 * @str: the string to modify
 */
void trim_whitespace(char *str)
{
	size_t len;
	size_t start = 0;
	size_t end;

	if (str != NULL)
	{
		len = strlen(str);
		end = len - 1;
		while (isspace((unsigned char)str[start]))
			start++;

		while (end > start && isspace((unsigned char)str[end]))
			end--;

		memmove(str, str + start, end - start + 1);
		str[end - start + 1] = '\0';
	}
}

/**
 * remove_newline - removes newline character from the end of a string
 * @str: the string to modify
 */
void remove_newline(char *str)
{
	size_t len;

	if (str != NULL)
	{
		len = strlen(str);

		if (len > 0 && str[len - 1] == '\n')
			str[len - 1] = '\0';
	}
}
