#include "unix.h"

/**
 * createEnv - function to set the environment variable
 * @comm: name of environment variable to be set
 * @soln: value of the environment variable
 * @replace: determines if there should be an overwrite
 * Return: Always 0
 */

int createEnv(const char *comm, const char *soln, int replace)
{
	if (setenv(comm, soln, replace) != 0)
	{
		perror("setenv");
	}
		return (0);
}

/**
 * unCreate - function to unset the environment variable
 * @comm: name of environment variable to be unset
 * Return: Always 0
 */

int unCreate(const char *comm)
{
	if (unsetenv(comm) != 0)
	{
		perror("Could not unset comm");
	}
	return (0);
}
