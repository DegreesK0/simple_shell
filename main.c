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
	char *exit_str = "exit";
	ssize_t read_input;
	bool interactive = true; /*aka not piped*/
	/* int i; */
	(void)argc;
	(void)argv;
	signal(SIGINT, ctrl_c_handler);

	while (1 && interactive)
	{
		if (isatty(STDIN_FILENO) == 0)
			interactive = false; /*interactive becomes non-interactive*/

		if (interactive == true)
			print_prompt();

		read_input = getline(&lineptr, &n, stdin);
		/* Allows Ctrl + D to exit on read_input fail*/
		if (read_input == -1)
		{
			free(lineptr);
			_putchar('\n');
			return (-1);
		}
		if (read_input == 1) /* Allows enter to work */
			continue;

		argv = tokenize_input(lineptr, read_input, argv);
		if (strcmp(argv[0], exit_str) == 0)
		{
			free_array(argv);
			free(lineptr);
			exit(0);
		}

		execute_commands(argv);
		free_array(argv);
	}
	free(lineptr);
	return (0);
}
