#include "shell.h"

/**
 * _strcat - concatenates a string to a different location
 * @destination: destination for the cat string
 * @source: source string
 * Return: resulting string
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
