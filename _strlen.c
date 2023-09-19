#include "shell.h"

/**
 *_strlen - checks the number of characters of a string
 *@str: the string with the elements to be counted
 *Return: the number of characters in the string
 */

size_t _strlen(const char *str)
{
	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}
