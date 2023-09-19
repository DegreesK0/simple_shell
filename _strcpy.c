#include "shell.h"

/**
 *
 */

void _strcpy(char *destination, const char *source)
{
	while (*source != '\0')
	{
		*destination = *source;
		source++;
		destination++;
	}
	*destination = '\0';
}
