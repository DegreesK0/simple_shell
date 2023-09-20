#include "shell.h"

/**
 * path_finder - finds the pth for the given cmd
 * @cmd: name of cmd to be executed
 * Return: 0
 */

char *path_finder(char *cmd)
{
	char *pth,  *pth_cpy, *pth_tok, *f_pth;
	int cmd_len, dir_len;
	struct stat buff;

	pth = _getenv("PATH");

	if (pth)
	{
		pth_cpy = _strdup(pth);
		cmd_len = _strlen(cmd);
		pth_tok = strtok(pth_cpy, ":");
	while (pth_tok != NULL)
	{
		dir_len = _strlen(pth_tok);
		f_pth = malloc(cmd_len + dir_len + 2);/*for / and null character*/
		_strcpy(f_pth, pth_tok);
		_strcat(f_pth, "/");
		_strcat(f_pth, cmd);
		_strcat(f_pth, "\0");
	if (stat(f_pth, &buff) == 0)
	{
		free(pth_cpy);
		return (f_pth);
	}
	else
	{
		free(f_pth);
		pth_tok = strtok(NULL, ":");
		}
	}
	free(pth_cpy);

	if (stat(cmd, &buff) == 0)
	{
		return (cmd);
	}
	return (NULL);
	}
return (NULL);
}
