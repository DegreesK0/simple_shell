#include "bkshell.h"

/**
 * main - runs a simple shell
 * @argc: argument count
 * @argv: argument values
 *
 * Return: 0 on success, -1 on fail. FOR NOW///
 */


int main(int argc, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t read_input;
	/* int i; */

	(void)argc;
	(void)argv;

	while (1)
	{
		print_prompt();
		read_input = getline(&lineptr, &n, stdin);
		/* Allows Ctrl + D to exit on read_input fail*/
		if (read_input == -1)
			return (-1);

		argv = tokenize_input(lineptr, read_input, argv);
		/* print out argv*/
		/* for (i = 0; argv[i] != NULL; i++) */
		/* { */
		/*	printf("%s\n", argv[i]); */
		/* } */
	}

	free(argv);
	free(lineptr);

	return (0);
}
