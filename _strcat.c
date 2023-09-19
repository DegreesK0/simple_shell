#include "shell.h"

/**
 *
 */

char *_strcat(char *destination, const char *source)
{
	char *result = destination;

	while (*destination != '\0')
	{
		destination++;
	}

	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}

	*destination = '\0';
	return (result);
}
