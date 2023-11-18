#include "shell_ver_three.h"

/**
 * _strdup - duplicates a string
 * @s: string
 * Return: duplicated string
 */
char *_strdup(const char *r)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - len of a string.
 * @s: pointer
 * Return: Always 0.
 */
int _strlen(const char *r)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - compare chars str
 * @str: string.
 * @divid: dividiter.
 *
 * Return: 1
 */
int cmp_chars(char str[], const char *divid)
{
	unsigned int z, m, a;

	for (z = 0, a = 0; str[z]; z++)
	{
		for (m = 0; divid[m]; m++)
		{
			if (str[z] == divid[m])
			{
				a++;
				break;
			}
		}
	}
	if (z == a)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string
 * @str: string.
 * @divid: dividier
 * Return: string
 */
char *_strtok(char str[], const char *divid)
{
	static char *separate , *str_end;
	char *str_start;
	unsigned int z, status;

	if (str != NULL)
	{
		if (cmp_chars(str, divid))
			return (NULL);
		separate  = str;
		z = _strlen(str);
		str_end = &str[z];
	}
	str_start = separate ;
	if (str_start == str_end)
		return (NULL);

	for (status = 0; *separate ; separate ++)
	{
		if (separate  != str_start)
			if (*separate  && *(separate  - 1) == '\0')
				break;
		for (z = 0; divid[z]; z++)
		{
			if (*separate  == divid[z])
			{
				*separate  = '\0';
				if (separate  == str_start)
					str_start++;
				break;
			}
		}
		if (status == 0 && *separate )
			status = 1;
	}
	if (status == 0)
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - string passed is a number
 * @s: string
 * Return: 1
 */
int _isdigit(const char *r)
{
	unsigned int z;

	for (z = 0; s[z]; z++)
	{
		if (s[z] < 48 || s[z] > 57)
			return (0);
	}
	return (1);
}

