#include "shell.h"

/**
 * print_string - prints the prompt for the shell
 * @string: string to be printed
 */

void print_string(char *string)
{
	/* char *prompt = "($) "; */
	int i;

	i = 0;

	while (string[i] != '\0')
	{
		_putchar(string[i]);
		i++;
	}
}
