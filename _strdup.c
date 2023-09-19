#include "shell.h"

/**
 *
 */

char *_strdup(const char *str)
{
	size_t len = _strlen(str);
	char *duplicate = (char *)malloc(len + 1);

	if (duplicate != NULL)
	{
		_strcpy(duplicate, str);
	}

	return (duplicate);
}
