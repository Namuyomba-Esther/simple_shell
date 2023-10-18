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
		size_t leng = strlen(command);

		givePrompt();
		if (leng > 0 && command[leng - 1] == '\n')
		command[leng - 1] = '\0';

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
		if (leng > 0 && command[leng - 1] == '\n')
			command[leng - 1] = '\0';
		if (command[0] == '#')
			continue;
		tokeniser(command, args, &argNo);
		if (toExit(args, argNo))
		{
			break;
		} else if (argNo == 1 && strcmp(args[0], "env") == 0)
		{
			giveEnv();
			continue;
		}
		createA("ls", "/bin/ls");
		listA("ls");
		executee(args);
	}
	return (0);
}
