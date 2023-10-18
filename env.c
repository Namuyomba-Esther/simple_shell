#include "unix.h"

/**
 * giveEnv - prints current environment variables
 */

void giveEnv(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		puts(*env);
		env++;
	}
}
