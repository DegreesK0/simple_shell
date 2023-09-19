#ifndef BKSHELL_H
#define BKSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/stat.h>

int _putchar(char c);
void print_string(char *string);
/* ssize_t read_input(void); */
char **tokenize_input(char *lineptr, ssize_t read_input, char **argv);
void execute_commands(char **argv);
void ctrl_c_handler(int signum);
void free_array(char **array);
void print_env(char **env);

ssize_t our_getline(char **lineptr, size_t *n, int fd);
char *our_strtok(char *str, const char *delimiters);

char *path_finder(char *command);

#endif
