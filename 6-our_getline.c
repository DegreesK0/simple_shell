#include "shell.h"

#define INITIAL_BUFFER_SIZE 100

/**
 * our_getline - works (hopefully) exactly like the getline function
 * @lineptr: buffer where text is stored. Dynamically allocates if NULL.
 * @n: size_t variable that holds the size of the buffer pointed to by lineptr
 * @fd: Use file descriptors instead FILE *stream because we are using read()
 *
 * Return: the total amount of characters read on success, -1 on failure
 */

ssize_t our_getline(char **lineptr, size_t *n, int fd)
{
	size_t buff_size = INITIAL_BUFFER_SIZE;
	size_t temp_buff_size = 0;
	ssize_t amount_read = 0;
	ssize_t input_read;
	int buff_index = 0;
	int i = 0;
	char *temp_pointer;
	char *buff_pointer;


	/* check input arguments */
	if (lineptr == NULL || n == NULL)
	{
		return (-1);
	}

	/* Allocate memory to buffer size if lineptr is NULL */
	if (*lineptr == NULL || *n == 0)
	{
		*n = buff_size;
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1);
		}
	}

	/* Dynamically adjust the amount of memory allocated*/
	while (1)
	{
		if (amount_read + buff_size + 1 >= *n)
		{
			temp_buff_size = (*n * 2);

			temp_pointer = malloc(temp_buff_size);
			if (temp_pointer == NULL)
			{
				return (-1);
			}

			for (i = 0; i < amount_read; i++)
			{
				temp_pointer[i] = (*lineptr)[i];
			}

			free(*lineptr);

			*lineptr = temp_pointer;
			*n = temp_buff_size;
		}

		/* Read characters using the read() system call */
		buff_pointer = *lineptr + amount_read;
		input_read = read(fd, buff_pointer, buff_size);

		if (input_read <= 0)
		{
			if (amount_read == 0)
				return (-1);
			else
				break;
		}

		amount_read += input_read;

		/* replacing the newline character with null-terminate character */
		for (i = buff_index; i < amount_read; i++)
		{
			if ((*lineptr)[i] == '\n')
			{
				(*lineptr)[i] = '\0';
				buff_index = i + 1;
				return (amount_read);
			}
		}

	}

	(*lineptr)[amount_read] = '\0';

	return (amount_read);
}
