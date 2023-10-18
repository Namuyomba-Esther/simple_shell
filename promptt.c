#include "unix.h"

/**
 * givePrompt - prints the prompt
 */

void givePrompt(void)
{
	char *prompt = "say_it:> ";

	write(1, prompt, strlen(prompt));
}
