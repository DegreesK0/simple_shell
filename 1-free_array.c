#include "shell.h"

/**
 * free_array - frees the array argv
 * @array: array argv
 *
 */

void free_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array[i]);
	free(array);
}
