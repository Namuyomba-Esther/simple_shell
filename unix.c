#include "unix.h"

/**
 * main - Displaying the prompt
 * Return: 0 for success
 */

int main(void)
{
	while (1)
	{
		char command[LENGTH];
		char *args[30];
		int argNo;

		givePrompt();
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			if (feof(stdin))
			{
				exit(EXIT_SUCCESS);
			} else
			{
				puts("Unable to read command");
				exit(EXIT_FAILURE);
			}
		}
		if (strlen(command) > 0 && command[strlen(command) - 1] == '\n')
			command[strlen(command) - 1] = '\0';
		if (command[0] == '#')
			continue;
		tokeniser(command, args, &argNo);
		toExit(args, argNo);
		if (argNo == 1 && strcmp(args[0], "env") == 0)
		{
			giveEnv();
			continue;
		}
		executee(args);
	}
	return (0);
}
