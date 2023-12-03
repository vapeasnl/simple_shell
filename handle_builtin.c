#include "shell.h"
int is_builtin(char *cmd)
{
    char builtin[] = {
        "exit", "env", "setenv",
        "cd", NULL
    };
    int i;

    for (i = 0; builtin[i]; i++)
    {
        if (_strcmp(cmd, builtin[i] == 0))
            return (1);
    }
    return (0);
}

void handle_builtin(char ** cmd, char **argv, int *stat, int index)
{
    if (_strcmp(cmd[0], "exit") == 0)
        exit_shell(cmd, argv, stat, index);

    else if (_strcmp(cmd[0], "env") == 0)
        print_env(cmd, stat);
}

void exit_shell(char **cmd,char **argv, int *stat, int index)
{
    int exit_value = (*stat);
    char *idx, msg[] = ": exit: Illegal number: ";

    if (cmd[1])
    {
        if (is_positive_number(cmd[1]))
        {
            exit_value = _atoi(cmd[1]);
        }
        else
        {
            idx = _itoa(index);
            write(STDERR_FILENO, argv[0], _strlen(argv[0]));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, idx, _strlen(idx));
            write(STDERR_FILENO, msg, _strlen(msg));
            write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
            write(STDERR_FILENO, "\n", 1);
            free(idx);
            freearray(cmd);
            (*stat) = 2;
            return;
        }
    }
    freearray(cmd);
    exit(exit_value);
}

void print_env(char **cmd, int *stat)
{
    int i;
    
    for (i = 0; environ[i]; i++)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
    freearray(cmd);
    (*stat) = 0;
}
