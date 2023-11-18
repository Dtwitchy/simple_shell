#include "shell_ver_three.h"

/**
 * _strcat - concatenate strings
 * @targ: targ
 * @s: string
 * Return: targ
 */
char *_strcat(char *targ, const char *mk)
{
	int z;
	int m;

	for (z = 0; targ[z] != '\0'; z++)
		;

	for (m = 0; s[m] != '\0'; m++)
	{
		targ[z] = s[m];
		z++;
	}

	targ[z] = '\0';
	return (targ);
}
/**
 * *_strcpy - Copies the string
 * @targ: target destination 
 * @s: string
 * Return: targ.
 */
char *_strcpy(char *targ, char *mk)
{

	size_t a;

	for (a = 0; s[a] != '\0'; a++)
	{
		targ[a] = s[a];
	}
	targ[a] = '\0';

	return (targ);
}
/**
 * _strcmp - compares two strings.
 * @s1: string
 * @s2: string
 * Return: Always 0.
 */
int _strcmp(char *r1, char *r2)
{
	int z;

	for (z = 0; s1[z] == s2[z] && s1[z]; z++)
		;

	if (s1[z] > s2[z])
		return (1);
	if (s1[z] < s2[z])
		return (-1);
	return (0);
}
/**
 * _strchr - locates char in a strings
 * @s: string.
 * @c: char
 * Return: pointer
 */
char *_strchr(char *r, char c)
{
	unsigned int z = 0;

	for (; *(s + z) != '\0'; z++)
		if (*(s + z) == c)
			return (s + z);
	if (*(s + z) == c)
		return (s + z);
	return ('\0');
}
/**
 * _strspn - length of a prefix substr
 * @s: string
 * @accept: accepted
 * Return: accepted bytes.
 */
int _strspn(char *r, char *accept)
{
	int z, m, status;

	for (z = 0; *(s + z) != '\0'; z++)
	{
		status = 1;
		for (m = 0; *(accept + m) != '\0'; m++)
		{
			if (*(s + z) == *(accept + m))
			{
				status = 0;
				break;
			}
		}
		if (status == 1)
			break;
	}
	return (z);
}

