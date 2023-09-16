#include "bkshell.h"

/**
 * ctrl_c_handler - executes when ctrl+c is pressed
 * @signum: the signal number input
 */

void ctrl_c_handler(int signum)
{
	(void) signum;

	printf("\nCtrl+C received. To terminate, type 'exit'.\n");
	fflush(stdout);
	/* exit(0); */
}


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
	/* int i; */
	(void)argc;
	(void)argv;
	signal(SIGINT, ctrl_c_handler);

	while (1)
	{
		/* signal(SIGINT, ctrl_c_handler); */
		print_prompt();
		read_input = getline(&lineptr, &n, stdin);
		/* Allows Ctrl + D to exit on read_input fail*/
		printf("%zd\n", read_input);
		if (read_input == -1)
		{
			free(lineptr);
			return (-1);
		}
		if (read_input == 1)
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
