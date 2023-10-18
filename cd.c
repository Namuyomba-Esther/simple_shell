#include "unix.h"

/**
 * toCd - function that changes directory
 * @newDir: name of the new directory
 * Return: Always 0
 */

int toCd(const char *path)
{
	const char *newDir = NULL;

	if (path == NULL || strcmp(path, "-") == 0)
	{
		newDir = getenv("HOME");
	} else if (strcmp(path, "-") == 0)
	{
		newDir = getenv("OLDPWD");
	} else
		newDir = path;

	if (chdir(newDir) == -1)
	{
		perror("cd");
	} else
	{
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", getcwd(NULL, 0), 1);
	}
	return (0);
}

