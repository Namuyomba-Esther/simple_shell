#include "unix.h"

/**
 * toExit - function checks to see if the user entered exit
 * @args: commands entered by user
 * @argNo: number of arguments entered
 * Return: 0 for success
 */

int toExit(char *args[], int argNo)
{
	int status;

	if (argNo == 1 && strcmp(args[0], "exit") == 0)
	{
		puts("Disconnecting...");
		exit(0);
	} else if (argNo > 1)
	{
		status = atoi(args[1]);
		exit(status);
	}
	return (0);
}
