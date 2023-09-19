#include "shell.h"

/**
 * main - runs a simple shell
 * @argc: argument count
 * @argv: argument values
 * @env: parameter for environment
 *
 * Return: 0 on success, -1 on fail. FOR NOW///
 */


int main(int argc, char **argv, char **env)
{
	char *lineptr = NULL;
	size_t n = 0;
	char *exit_str = "exit";
	char *env_str = "env";
	ssize_t read_input;
	bool interactive = true; /*aka not piped*/
	/* int i; */
	(void)argc;
	(void)argv;
	(void)env;
	signal(SIGINT, ctrl_c_handler);

	while (1)
	{
		if (isatty(STDIN_FILENO) == 0)
			interactive = false; /*interactive becomes non-interactive*/

		if (interactive == true)
			print_string("($) ");

		read_input = getline(&lineptr, &n, stdin);
		/* read_input = our_getline(&lineptr, &n, 0);*/
		/* /1* stdin = 0 (file descriptor) *1/ */
		/* Allows Ctrl + D to exit on read_input fail*/
		if (read_input == -1)
		{
			if (interactive == true)
			{
				free(lineptr);
				_putchar('\n');
			}
			return (0);
		}
		/* if (read_input == 1) /1* Allows enter to work *1/ */
		/* continue; */

		argv = tokenize_input(lineptr, read_input, argv);

		if (argv == NULL)
		{
			free(argv);
			continue;
		}
		if (_strcmp(argv[0], exit_str) == 0)
		{
			free_array(argv);
			free(lineptr);
			exit(0);
		}
		if (_strcmp(argv[0], env_str) == 0)
		{
			print_env(env);
			continue;
		}

		execute_commands(argv);
		free_array(argv);
	}
	free(lineptr);
	return (0);
}
