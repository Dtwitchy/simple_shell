#include "main.h"

/**
 * main - start of the shell
 * Return: 0 for success
 */
int main(void)
{
	char *start_prompt = "partners$ ";
	char input[1024];

	while (strcmp(input, "exit") != 0)
	{
		printf("%s", start_prompt);
		scanf("%s", input);
		printf("%s\n", input);
	}

	return (0);
}
