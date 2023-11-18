#include "shell_ver_three.h"

/**
 * cd_pad - moves to the parent directory
 *
 * @datash: relevant data
 *
 * Return: none
 */
void cd_pad(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *d, *clone_pwd, *clone_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	clone_pwd = _strdup(pwd);
	set_env("OLDPWD", clone_pwd, datash);
	d = datash->args[1];
	if (_strcmp(".", d) == 0)
	{
		set_env("PWD", clone_pwd, datash);
		free(clone_pwd);
		return;
	}
	if (_strcmp("/", clone_pwd) == 0)
	{
		free(clone_pwd);
		return;
	}
	clone_strtok_pwd = clone_pwd;
	rev_string(clone_strtok_pwd);
	clone_strtok_pwd = _strtok(clone_strtok_pwd, "/");
	if (clone_strtok_pwd != NULL)
	{
		clone_strtok_pwd = _strtok(NULL, "\0");

		if (clone_strtok_pwd != NULL)
			rev_string(clone_strtok_pwd);
	}
	if (clone_strtok_pwd != NULL)
	{
		chdir(clone_strtok_pwd);
		set_env("PWD", clone_strtok_pwd, datash);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", datacd);
	}
	datash->status = 0;
	free(clone_pwd);
}

/**
 * cd_to - changes to a directory given
 *
 * @datash: relevant data
 * Return: none
 */
void cd_to(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *d, *clone_pwd, *clone_d;

	getcwd(pwd, sizeof(pwd));

	d = datash->args[1];
	if (chdir(d) == -1)
	{
		get_error(datacd, 2);
		return;
	}

	clone_pwd = _strdup(pwd);
	set_env("OLDPWD", clone_pwd, datash);

	clone_d = _strdup(d);
	set_env("PWD", clone_d, datash);

	free(clone_pwd);
	free(clone_d);

	datash->status = 0;

	chdir(d);
}

/**
 * cd_prvsd - move to the previous directory
 *
 * @datash: relevant data
 * Return: none
 */
void cd_prvsd(data_shell *datash)
{
	char pwd[PATH_MAX];
	char *pointer_pwd, *pointer_oldpwd, *clone_pwd, *clone_oldpwd;

	getcwd(pwd, sizeof(pwd));
	clone_pwd = _strdup(pwd);

	pointer_oldpwd = _getenv("OLDPWD", datacd->_environ);

	if (pointer_oldpwd == NULL)
		clone_oldpwd = clone_pwd;
	else
		clone_oldpwd = _strdup(pointer_oldpwd);

	set_env("OLDPWD", clone_pwd, datash);

	if (chdir(clone_oldpwd) == -1)
		set_env("PWD", clone_pwd, datash);
	else
		set_env("PWD", clone_oldpwd, datash);

	pointer_pwd = _getenv("PWD", datash->_environ);

	write(STDOUT_FILENO, pointer_pwd, _strlen(pointer_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(clone_pwd);
	if (pointer_oldpwd)
		free(clone_oldpwd);

	datash->status = 0;

	chdir(pointer_pwd);
}

/**
 * cd_to_home - moves to home directory
 *
 * @datash: relevant data
 * Return: none
 */
void cd_to_home(data_shell *datash)
{
	char *pointer_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	pointer_pwd = _strdup(pwd);

	home = _getenv("HOME", datash->_environ);

	if (home == NULL)
	{
		set_env("OLDPWD", pointer_pwd, datash);
		free(pointer_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_error(datash, 2);
		free(pointer_pwd);
		return;
	}

	set_env("OLDPWD", pointer_pwd, datash);
	set_env("PWD", home, datacd);
	free(pointer_pwd);
	datash->status = 0;
}

