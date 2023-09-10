#include "bkshell.h"

/**
 *
 */

void execute_commands(char **argv)
{
	char *command = NULL;

	if (argv)
	{
	    /* get the command */
		command = argv[0];

	    /* execute the actual command with execve */
		if (execve(command, argv, NULL) == -1){
			perror("Error");
	    }
	}
}
