#include "shell.h"

/**
 * path_finder - finds the path for the given command
 * @command: name of command to be executed
 * Return: 0
 */

char *path_finder(char *command)
{
	char *path,  *path_copy, *path_token, *file_path;
	int cmd_length, dir_length;
	struct stat buffer;

	path = _getenv("PATH");

	if (path)
	{
		path_copy = _strdup(path);
		cmd_length = _strlen(command);
		path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		dir_length = _strlen(path_token);
		file_path = malloc(cmd_length + dir_length + 2);/*for / and null character*/
		_strcpy(file_path, path_token);
		_strcat(file_path, "/");
		_strcat(file_path, command);
		_strcat(file_path, "\0");
	if (stat(file_path, &buffer) == 0)
	{
		free(path_copy);
		return (file_path);
	}
	else
	{
		free(file_path);
		path_token = strtok(NULL, ":");
		}
	}
	free(path_copy);

	if (stat(command, &buffer) == 0)
	{
		return (command);
	}
	return (NULL);
	}
return (NULL);
}
