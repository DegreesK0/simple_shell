#ifndef BKSHELL_H
#define BKSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int _putchar(char c);
void print_prompt(void);
/* ssize_t read_input(void); */
char **tokenize_input(char *lineptr, ssize_t read_input, char **argv);
void execute_commands(char **argv);
/* void ctrl_c_handler(int signum); */
void free_array(char **array);

#endif
