#include "bkshell.h"

/**
 * execute_commands - Takes commands from argv, looks for them in PATH (execvp)
 * @argv: array of input commands
 *
 */

void execute_commands(char **argv)
{
	char *command = NULL;

	if (argv)
	{
	    /* get the command */
		command = argv[0];

	    /* execute the actual command with execvp */
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error");
		}
	}
}
