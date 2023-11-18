#include "shell_version_two.h”

/**
 * cd_current - change current directory 
 *
 * @datacd: relevant data
 * Return: 1 (success)
 */
int cd_current(data_shell *datacd)
{
	char *d;
	int r, k, i;

	d = datacd->args[1];

	if (d != NULL)
	{
		r = _strcmp("$HOME", d);
		k = _strcmp("~", d);
		i = _strcmp("--", d);
	}

	if (d == NULL || !r || !k || !i)
	{
		cd_to_home(datacd);
		return (1);
	}

	if (_strcmp("-", d) == 0)
	{
		cd_prvsd(datacd);
		return (1);
	}

	if (_strcmp(".", d) == 0 || _strcmp("..", d) == 0)
	{
		cd_pad(datacd);
		return (1);
	}

	cd_to(datacd);

	return (1);
}

