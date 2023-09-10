#include "bkshell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: character to write to output
 *
 * Return: 1 on success, -1 on failure
 */


int _putchar(char c)
{
	return (write(1, &c, 1));
}
