#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>




void exec_command(char *lineptr, ssize_t read_input, char **argv, char **env);

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
	ssize_t read_input;
	size_t n = 0;
	char *lineptr = NULL;

	(void)argc;
	(void)env;

	while (1)
	{
		print_string("($) ");
		/* fgets(input, BUFFER_SIZE, stdin); */
		read_input = getline(&lineptr, &n, stdin);

		lineptr[strlen(lineptr) - 1] = '\0';

		if (strcmp(lineptr, "exit") == 0)
		{
			/* printf("Exiting the shell...\n"); */
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
 * complete.
 */
/* void execute_command(const char *command) */
void exec_command(char *lineptr, ssize_t read_input, char **args, char **env)
{
	pid_t pid_child = fork();
	/* char *executable, *full_path, *full_command; */
	/* char *env[] = {NULL}; */

	char *executable = NULL;
	char *actual_command = NULL;
	char *env_str = "env";

	if (pid_child == -1)
	{
		perror("Fork failed");
	}
	else if (pid_child == 0)
	{
		args = tokenize_input(lineptr, read_input, args);
		if (_strcmp(args[0], env_str) == 0)
		{
			print_env(env);
			/* continue; */
		}


		executable = args[0];
		actual_command = path_finder(executable);
		/* Execute the actual commands with execve */
		/* if (execsp(command, argv) == -1) */
		if (execve(actual_command, args, NULL) == -1)
		{
			perror("Exec Error");
			exit(EXIT_FAILURE);
		}
		free_array(args);
	}
	else
	{
		/* Parent process */
		int status;

		waitpid(pid_child, &status, 0);
	}
}
