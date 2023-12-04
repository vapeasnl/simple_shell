#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;

char *read_line(void);
char *_strcpy(char *dest, char *src);
char *_stdrup(const char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
void freearray(char **arr);
char **tokenizer(char *l);
int _execute(char **cmd, char **argv, int index);
char *_getenv(char *var);
char *_getpath(char *cmd);
void printerror(char *name, char *cmd, int index);
void reverse_string(char *str, int lenght);
char *_itoa(int n);
void handle_builtin(char **cmd, char **argv, int *stat, int index);
int is_builtin(char *cmd);
void exit_shell(char **cmd, char **argv, int *stat, int index);
void print_env(char **cmd, int *stat);
int _atoi(char *str);
int is_positive_number(char *str);

#endif