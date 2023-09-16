#include "bkshell.h"

/**
 * ctrl_c_handler - executes when ctrl+c is pressed
 * @signum: the signal number input
 */

void ctrl_c_handler1(int signum)
{
	(void) signum;
	signal(SIGINT, ctrl_c_handler1);
	printf("\n cannot terminate \n");
	fflush(stdout);
	/* exit(0); */
}
