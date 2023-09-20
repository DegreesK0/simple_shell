#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* #define BUFFER_SIZE 1024 */

/* void execute_command(const char *command); */
int execute_command(char *command, ssize_t read_input, char **argv, char **env);

/**
 * main - Entry point of the shell program.
 *
 * Description: Reads user input, executes commands, and exits o"exit" command.
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
		/* fgets(input, BUFFER_SIZE, stdin); */
		read_input = getline(&lineptr, &n, stdin);

		/* input[strlen(input) - 1] = '\0'; */

		if (strcmp(lineptr, "exit\n") == 0)
		{
			/* printf("Exiting the shell...\n"); */
			break;
		}

		/* if (read_input == -1) */
		/* { */

		/* 	free(lineptr); */
		/* 	_putchar('\n'); */

		/* 	return (0); */
		/* } */


		execute_command(lineptr, read_input, argv, env);
	}

	free(lineptr);
	return (0);
}

/**
 * execute_command - Execute a given command.
 *
 * @command: The command to execute.
 *
 * Description: Forks a child process to execute the commandand waits for it to
 * complete.
 */
/* void execute_command(const char *command) */
int execute_command(char *lineptr, ssize_t read_input, char **args, char **env)
{
	pid_t pid = fork();
	/* char *executable, *full_path, *full_command; */
	/* char *env[] = {NULL}; */

	char *executable = NULL;
	char *actual_command = NULL;
	/* char *exit_str = "exit"; */
	char *env_str = "env";

	if (pid == -1)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		/* child process*/
		/* char *args[64]; */
		/* char *token = strtok((char *)command, " \n"); */
		/* int i = 0; */

		/* while (token != NULL) */
		/* { */
		/* 	args[i++] = token; */
		/* 	token = strtok(NULL, " \n"); */
		/* } */

		/* args[i] = NULL; */

		args = tokenize_input(lineptr, read_input, args);
		/* if (args == NULL) */
		/* { */
		/* 	free(argv); */
		/* 	continue; */
		/* } */
		/* if (_strcmp(args[0], exit_str) == 0) */
		/* { */
		/* 	free_array(args); */
		/* 	free(lineptr); */
		/* 	exit(0); */
		/* } */
		if (_strcmp(args[0], env_str) == 0)
		{
			print_env(env);
			/* continue; */
		}

		/* Specify the full path to the executable */
		/* executable = args[0]; */
		/* full_path = "/bin/"; /1* Adjust this path as needed *1/ */
		/* full_command = */
		/*     malloc(strlen(full_path) + strlen(executable) + 1); */
		/* if (full_command == NULL) */
		/* { */
		/* 	perror("Memory allocation failed"); */
		/* 	exit(EXIT_FAILURE); */
		/* } */

		/* strcpy(full_command, full_path); */
		/* strcat(full_command, executable); */

		/* /1* Prepare environment variables (optional) *1/ */

		/* if (execve(full_command, args, env) == -1) */
		/* { */
		/* 	perror("Command execution failed"); */
		/* 	exit(EXIT_FAILURE); */
		/* } */

		/* free(full_command); */



		executable = args[0];
		actual_command = path_finder(executable);
		/* Execute the actual commands with execve */
		if (execve(actual_command, args, NULL) == -1)
		/* if (execvp(command, argv) == -1) */
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

		waitpid(pid, &status, 0);
	}

	return (0);
}
