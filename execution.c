#include "unix.h"

/**
 * executee - function executes the user input
 * @args: Input from the user
 * Return: Always 0
 */

int executee(char *args[])
{
	int status;
	pid_t cpid = fork();

	if (cpid < 0)
	{
		perror("Unable to fork process");
		return (1);
	}

	if (cpid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
			exit(1);
		}
	} else
	{
		if (waitpid(cpid, &status, 0) == -1)
		{
			perror("waitpid");
			return (EXIT_FAILURE);
		}
	}
	return (0);
}
