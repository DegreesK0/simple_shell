#ifndef BKSHELL_H
#define BKSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int _putchar(char c);
void print_prompt(void);
/* ssize_t read_input(void); */
char **tokenize_input(char *lineptr, ssize_t read_input, char **argv);
void execute_commands(char **argv);

#endif
