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

char *_readline(void);
char *_cpy(char *dest, char *src);
char *_dup(const char *str);
char *_cat(char *dest, char *src);
int _cmp(char *s1, char *s2);
int _len(char *s);
void _farray(char **arr);
char **_tkn(char *l);
int _exec(char **cmd, char **argv, int ind);
char *_getenv(char *var);
char *_getpath(char *cmd);
void _errorprint(char *name, char *cmd, int ind);
void _rstring(char *str, int len);
char *_itoa(int n);
void _hb(char **cmd, char **argv, int *st, int ind);
int _ib(char *cmd);
void _exit_sh(char **cmd, char **argv, int *st, int ind);
void _printenv(char **cmd, int *st);
int _atoi(char *str);
int _moujab(char *str);

#endif
