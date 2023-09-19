#include "shell.h"

/**
 *print_env - displays the current working environment
 *@env: the current working environment
 */

void print_env(char **env)
{
	int i = 0;

	for (i = 0; env[i] != NULL; i++)
	{
		print_string(env[i]);
		_putchar('\n');
	}
}
