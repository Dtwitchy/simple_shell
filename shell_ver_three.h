#ifndef SHELL_VER_THREE
#define SHELL_VER_THREE

/* Macro Definitions */
#define ONLINE 1
#define MAX_NUM_ARGUMENTS 64
#define MAX_INPUT_SIZE 1024
#define BUFFER 128

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
void remove_newline(char *command);
void trim_whitespace(char *command);
char **tokenizer(char *input);
int handle_var(char *command, char *arguments[], int cmd_status, int pid);
int builtin_exit(char *command, char *arguments[], int cmd_status);
int builtin_env(char *command, char **environ);

/* Custom Functions */
ssize_t input(char **lineptr, size_t *size, FILE *stream);
char *mod_strtok(char *str, const char *delimiters, char **saveptr);

/* Custom Default C Functions */
size_t length(const char *str);
char *resize(char *ptr, size_t size);
char *construct_full_command(const char *path, const char *command);

/* New From Destiny */
/**
void cd_pad(data_cmd *datacd);
void cd_to(data_cmd *datacd);
void cd_prvsd(data_cmd *datacd);
void cd_to_home(data_cmd *datacd);
int cd_cmd(data_cmd *datacd);
char *_strdup(const char *r);
int _strlen(const char *r);
int cmp_chars(char str[], const char *divid);
char *_strtok(char str[], const char *divid);
int _isdigit(const char *r);
char *_strcat(char *targ, const char *mk);
char *_strcpy(char *targ, char *mk);
int _strcmp(char *r1, char *r2);
char *_strchr(char *r, char c);
int _strspn(char *r, char *accept);
void rev_string(char *r);


void cd_pad(data_cmd *datacd);
void cd_to(data_cmd *datacd);
void cd_prvsd(data_cmd *datacd);
void cd_to_home(data_cmd *datacd);
*/

/* External Variables Needed */
extern char **environ;

#endif
