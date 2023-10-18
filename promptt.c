#include "unix.h"

/**
 * givePrompt - prints the prompt
 */

void givePrompt(void)
{
	write(1, "say_it:> ", strlen("say_it:> "));
	fflush(stdout);
}
