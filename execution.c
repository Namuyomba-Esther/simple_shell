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
	char *envn[] = { NULL };
	char *pathArg = args[0];

	if (cpid == 0)
	{
		execve(pathArg, args, envn);
		perror("Unable to execute command");
		exit(EXIT_FAILURE);
	} else if (cpid < 0)
	{
		perror("Unable to fork process");
		exit(1);
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
