#include "bkshell.h"

/**
 * print_prompt - prints the prompt for the shell
 */

void print_prompt(void)
{
	char *prompt = "($) ";
	int i;

	i = 0;

	while (prompt[i] != '\0')
	{
		_putchar(prompt[i]);
		i++;
	}
}
