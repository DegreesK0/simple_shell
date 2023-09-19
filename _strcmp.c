#include "shell.h"

/**
 *_strcmp - compares different strings
 *@str1: pointer to first string
 *@str2: pointer to second string
 *Return: difference between the two strings
 */

int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}

	return (*str1 - *str2);
}
