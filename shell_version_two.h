#ifndef MAIN_H
#define MAIN_H

/* Macro Definitions */
#define ONLINE 1
#define MAX_NUM_ARGUMENTS 64
#define MAX_INPUT_SIZE 1024
#define BUFFER 1024

/* Inclusions */
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

/* Prototypes */
int execute(char *command, char *arguments[], char *envp[]);
int process(char *command, char *arguments[], char *envp[], int prepend);
void remove_newline(char *command);
void trim_whitespace(char *command);
char **tokenizer(char *input);
int handle_var(char *command, char *arguments[], int cmd_status, int pid);
int builtin_exit(char *command, char *arguments[], int cmd_status);
int builtin_env(char *command, char **environ);
ssize_t input(char **lineptr, size_t *n, FILE *stream);
void cd_pad(data_cmd *datacd);
void cd_to(data_cmd *datacd);
void cd_prvsd(data_cmd *datacd);
void cd_to_home(data_cmd *datacd);
int cd_current(data_cmd *datacd);



/* External Variables Needed */
extern char **environ;

#endif
