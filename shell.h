#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcnl.h>

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



#endif
