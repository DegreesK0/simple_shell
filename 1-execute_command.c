#include "shell.h"

/**
 * execute_commands - Takes commands from argv, looks for them in PATH (execvp)
 * @argv: array of input commands
 *
 */

void execute_commands(char **argv)
{
	char *command = NULL;
	char *actual_command = NULL;
	pid_t child_pid;
	int status;


	if (argv)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Fork Error");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			/* Set the first command */
			command = argv[0];
			actual_command = path_finder(command);
			/* Execute the actual commands with execve */
			if (execve(actual_command, argv, NULL) == -1)
			{
				perror("Exec Error");
				exit(EXIT_FAILURE);
			}

		}
		else
		{
			/* This is executed by the parent process */
			/* Waiting for the child process to finish */
			if (waitpid(child_pid, &status, 0) == -1)
			{
				perror("Waitpid failed");
				exit(EXIT_FAILURE);
			}
		}
	}
}
