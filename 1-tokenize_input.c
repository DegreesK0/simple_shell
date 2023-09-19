#include "shell.h"

/**
 * tokenize_input - tokenizes the input and stores it in the array argv
 * @lineptr: pointer to the line/string being tokenized
 * @read_input: number of chars read from the input
 * @argv: the array of argument values
 *
 * Return: the array argv[]
 */

char **tokenize_input(char *lineptr, ssize_t read_input, char **argv)
{
	const char delimiters[] = " \n"; /* Delimiters: space and newline*/
	char *token, *lineptr_cpy = NULL;
	int num_toks = 0, i = 0;

	/* Let's count the number of tokens!!! */
	/* Assign memory for the copy of lineptr to use for counting*/
	lineptr_cpy = malloc(sizeof(char) * read_input);
	if (lineptr_cpy == NULL)
	{
		perror("Error message to specify");
		return (NULL);
	}
	_strcpy(lineptr_cpy, lineptr); /* Copy lineptr to lineptr_cpy */
	/* Count the tokens */
	token = strtok(lineptr_cpy, delimiters);
	if (token == NULL)
	{
		free(lineptr_cpy);
		return (NULL);
	}

	for (num_toks = 0; token != NULL; ++num_toks)
	{
		token = strtok(NULL, delimiters);
	}
	num_toks++; /* One more count to make space for NULL */
	/* Now, let's assign tokens to array (of pointers) argv!!!*/
	argv = malloc(sizeof(char *) * num_toks); /*Make space for each token*/
	/*Store each item/token in the argv*/
	token = strtok(lineptr, delimiters);
	/* token = strtok(lineptr, delimiters); */
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token)); /*Make space for each token*/
		if (argv[i] == NULL)
		{
			free(lineptr_cpy);
			perror("Error message to specify");
			return (NULL);
		}
		_strcpy(argv[i], token); /*Copy the token into array item of argv*/
		token = strtok(NULL, delimiters);
	}
	argv[i] = NULL; /*Last item in array set to NULL*/
	free(lineptr_cpy);
	return (argv);
}
