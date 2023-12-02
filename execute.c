#include "shell.h"
int _execute(char **cmd, char **argv, int index)
{
    char *full_cmd;
    pid_t child;
    int stat;

    full_cmd = _getpath(cmd[0]);
    if (!full_cmd)
    {
        printerror(argv[0], cmd[0], index);
        freearray(cmd);
        return (127);
    }

    child = fork();
    if (child == 0)
    {
        if (execve(full_cmd, cmd[0], cmd, environ) == -1)
        {
            free(full_cmd), full_cmd = NULL;
            freearray(cmd);
        }
    }
    else
    {
        waitpid(child, &stat, 0);
        freearray(cmd);
        free(full_cmd), full_cmd = NULL;
    }
    return (WEXITSTATUS(stat));
}
