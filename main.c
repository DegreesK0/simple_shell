#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* #define BUFFER_SIZE 1024 */

/* void execute_command(const char *command); */
int exec_command(char *command, ssize_t read_input, char **argv, char **env);

/**
 * main - Entry point of the shell program.
 * @argc: argument count
 * @argv: argument values
 * @env: parameter for environment
 *
 * Return: Always returns 0.
 */

int main(int argc, char **argv, char **env)
{
	/* char input[BUFFER_SIZE]; */
	ssize_t read_input;
	size_t n = 0;
	char *lineptr = NULL;

	(void)argc;
	(void)env;

	while (1)
	{
		print_string("($) ");
		read_input = getline(&lineptr, &n, stdin);


		if (strcmp(lineptr, "exit\n") == 0)
		{
			break;
		}

		exec_command(lineptr, read_input, argv, env);
	}

	free(lineptr);
	return (0);
}

/**
 * exec_command - Execute a given command.
 * @lineptr: the pointer to the line
 * @read_input: input read
 * @args: argv input
 * @env: environment
 *
 * Description: Forks a child process to execute the commandand waits for it to
 * complete
 *
 * Return: 0 on success
 */

/* void execute_command(const char *command) */
int exec_command(char *lineptr, ssize_t read_input, char **args, char **env)
{
	pid_t pid = fork();


	char *executable = NULL;
	char *actual_command = NULL;
	char *env_str = "env";

	if (pid == -1)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		args = tokenize_input(lineptr, read_input, args);

		if (_strcmp(args[0], env_str) == 0)
		{
			print_env(env);
		}
		executable = args[0];
		actual_command = path_finder(executable);
		if (execve(actual_command, args, NULL) == -1)
		{
			perror("Exec Error");
			exit(EXIT_FAILURE);
		}

		free_array(args);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}

	return (0);
}
