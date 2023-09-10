#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **argv)
{

	char *prompt = "(Eshell) $";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	/* int counter = 0; */
	char *token;
	int i = 0;


	(void)ac;
	/* (void)argv; */

	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
				return (-1);
		}

		/* allocate space for a copy of the lineptr */
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		/* copy lineptr to lineptr_copu */
		strcpy(lineptr_copy, lineptr);

	/********** split the string (lineptr) into an array of words ********/
		/* calculate the total number of tokens */
		token = strtok(lineptr, delim);


		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;

		/* Allocate space to hold the array of strings */
		argv = malloc(sizeof(char *) * num_tokens);

		/* Store each token in the argv array */
		token = strtok(lineptr_copy, delim);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);

			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		execmd(argv);

		/* printf("%s\n", lineptr); */

		/* print the content of argv */
		/* for (counter = 0; counter<num_tokens-1; counter++) */
		/* { */
		/* 	printf("%s\n", argv[counter]); */
		/* } */
	}
		free(lineptr_copy);
		free(lineptr);

	return (0);
}
