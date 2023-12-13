#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DELIM " \t\n\r\a"

extern char **environ;

/*main.c*/
int _exec(char **cmd, char **argv, int ind);
/*exec.c*/
void _farray(char **arr);
void _errorprint(char *name, char *cmd, int ind);
void _rstring(char *str, int len);
int _moujab(char *str);
/*tkn.c*/
char **_tkn(char *l);
/*libstr.c*/
char *_cpy(char *dest, char *src);
char *_dup(const char *str);
char *_cat(char *dest, char *src);
int _cmp(char *s1, char *s2);
int _len(char *s);
/*f1.c*/
void _farray(char **arr);
void _errorprint(char *name, char *cmd, int ind);
void _rstring(char *str, int len);
int _moujab(char *str);
/*f2.c*/
int _atoi(char *str);
char *_itoa(int n);
/*f3.c*/
char *_getpath(char *cmd);
char *_getenv(char *var);
char *_rline(void);
/*f4.c*/
int _ib(char *cmd);
void _hb(char **cmd, char **argv, int *st, int ind);
void _exit_sh(char **cmd, char **argv, int *st, int ind);
void _printenv(char **cmd, int *st);


#endif
