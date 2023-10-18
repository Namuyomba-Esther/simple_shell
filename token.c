#include "unix.h"

/**
 * tokeniser - function that tokenises arguments
 * @command: User input
 * @args: Array of arguments
 * @argNo: Number of arguments
 */

void tokeniser(char *command, char *args[], int *argNo)
{
	char *token;
	*argNo = 0;
	token = strtok(command, " ");

	while (token != NULL)
	{
		args[(*argNo)++] = token;
		token = strtok(NULL, " ");
	}
	args[*argNo] = NULL;
}
