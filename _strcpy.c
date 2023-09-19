#include "shell.h"

/**
 *_strcpy - copis the elements of a given string
 *@destination: destination of copied string
 *@source: string to be copied
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
