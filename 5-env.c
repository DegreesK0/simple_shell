#include "shell.h"

/**
 *
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
