#include "main.h"
/**
* _exec Execute a command
* @cmd: Array of strings representing the command and its arguments
* @argv: Array of strings representing the program and its arguments
* @ind: Index of the command in the argv array
* Return: Exit status of the executed command
*/
int _exec(char **cmd, char **argv, int ind)
{
        int st;
        char *ccmd;
        pid_t ppid;

        ccmd = _getpath(cmd[0]);
        if (!ccmd)
        {
                _errorprint(argv[0], cmd[0], ind);
                _farray(cmd);
                return (127);
        }

        ppid = fork();
        if (ppid == 0)
        {
                if (execve(ccmd, cmd, environ) == -1)
                {
                        free(ccmd), _farray(cmd);
                }
        }
        else
        {
                waitpid(ppid, &st, 0);
                _farray(cmd), free(ccmd);
        }
        return (WEXITSTATUS(st));
}
