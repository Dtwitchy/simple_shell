#ifndef MAIN_H
#define MAIN_H

/* Macro Definitions */
#define ONLINE 1
#define MAX_NUM_ARGUMENTS 64

/* Inclusions */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* Prototypes */
void prompt(void);
int input(char **input);
char **tokenizer(char *input);
int execute(char *tokenized_command, char **arguments);
char *find_path(char *tokenized_command);
char *build_path(char *path_directory, char *tokenized_command);

/* External Variables Needed */
extern char **environ;

#endif
