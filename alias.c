#include "unix.h"

/**
 * createA - function that sets aliases
 * @name: assigned name of the alias
 * @value: string assigned to the name
 */

void createA(const char *name, const char *value)
{
	struct Alias aliasses[20];
	int aliassesNo = 0;

	for (aliassesNo = 0; aliassesNo < 20; aliassesNo++)
	{
		if (strcmp(aliasses[aliassesNo].name, name) == 0)
		{
			strcpy(aliasses[aliassesNo].value, value);
			return;
		}
	}
	strcpy(aliasses[aliassesNo].name, name);
	strcpy(aliasses[aliassesNo].value, value);
	aliassesNo++;
	if (aliassesNo == 20)
	{
		puts("No more aliases needed");
	}
}

/**
 * listA - prints and lists aliases
 * @name: assigned name of the alias
 */

void listA(const char *name)
{
	int j = 0;
	struct Alias aliasses[20];
	int aliassesNo = 0;

	while (j < aliassesNo)
	{
		if (strcmp(aliasses[j].name, name) == 0)
		{
			puts(aliasses[j].name);
			puts("=");
			puts(aliasses[j].value);
		}
		j++;
	}
	if (j == aliassesNo)
		puts("Unable to find alias");
}

