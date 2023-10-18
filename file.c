#include "unix.h"

/**
 * exefile - executes and prints contents in a file
 * @filename: name of file
 * Return: Always 0 for success
 */

void exefile(const char *filename)
{
	char command[LENGTH];
	FILE *project;

	project = fopen(filename,  "r");

	if (project == NULL)
	{
		perror("Could not open file");
	}

	while (fgets(command, sizeof(command), project))
	{
		system(command);
	}
	fclose(project);
}
