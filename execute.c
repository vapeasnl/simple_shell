#include "shell.h"
int _execute(char **cmd, char **argv)
{
    pid_t child;
    int stat;

    chlid = fork();
    if (child == 0)
    {
        if (execve(cmd[0], cmd, environ) == -1)
        {
            perror(argv[0]);
            freearray(cmd);
            exit(0);
        }
    }
    else
    {
        waitpid(child, &stat, 0);
        freearray(cmd);
    }
    return (WEXITSTATUS(stat));
}
