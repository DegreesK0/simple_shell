#include "bkshell.h"

/**
 * ctrl_c_handler - executes when ctrl+c is pressed
 * @signum: the signal number input
 */

void ctrl_c_handler(int signum)
{
	(void) signum;
	printf("\n^C\n");
}
