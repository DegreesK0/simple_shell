#include "shell.h"

#define INITIAL_BUFFER_SIZE 100

/**
 * our_getline - works (hopefully) exactly like the getline function
 * @lineptr: buffer where text is stored. Dynamically allocates if NULL.
 * @n: size_t variable that holds the size of the buffer pointed to by lineptr
 * @stream: Use FILE *stream
 * Return: the total amount of characters read on success, -1 on failure
 */

ssize_t our_getline(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	size_t i = 0;
	char *new_ptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		errno = EINVAL;
		return (-1);
	}
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			perror("Memory allocation failed");
			return (-1);
		}
	}
	while ((ch = fgetc(stream)) != EOF)
	{
		if (i + 1 >= *n)
		{
			*n *= 2;
			new_ptr = (char *)realloc(*lineptr, *n);
			if (new_ptr == NULL)
			{
				perror("Memory reallocation failed");
				return (-1);
			}
			*lineptr = new_ptr;
		}
		(*lineptr)[i++] = (char)ch;
		if (ch == '\n')
			break;
	}
	(*lineptr)[i] = '\0';
	if (i == 0 && ch == EOF)
		return (-1);
	return ((ssize_t)i);
}
