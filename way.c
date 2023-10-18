#include "unix.h"

/**
 * givePath - prints the PATH environment variable
 * Return: 0 for failure to execute
 */

char *givePath(void)
{
	char *path = "/bin";
	char pathCmd[200];
	char cmd[] = "pwd";

	snprintf(pathCmd, sizeof(pathCmd), "%s/%s", path, cmd);
	if (access(pathCmd, X_OK) == 0)
	{
		return (strdup(pathCmd));
		free(path);
	}
	return (0);
}
