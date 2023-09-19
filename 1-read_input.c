#include "shell.h"

/**
 * read_input - Reads the line input by the user
 *
 * Return: Returns the number of characters read
 */

ssize_t read_input(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t chars_read;

	chars_read = getline(&lineptr, &n, stdin);

	/*testing by printing*/
	/* printf("%s", lineptr); */

	free(lineptr);
	return (chars_read);
}
