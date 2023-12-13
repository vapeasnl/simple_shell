#include "main.h"
/**
* _exec --
* @cmd: --
* @argv: --
* @index: --
* Return: --
*/
int _exec(char **cmd, char **argv, int index)
{
	int st;
	char *ccmd;
	pid_t child;

	ccmd = _getpath(cmd[0]);
	if (!ccmd)
	{
		_errorprint(argv[0], cmd[0], index);
		_farray(cmd);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(ccmd, cmd, environ) == -1)
		{
			free(ccmd), _farray(cmd);
		}
	}
	else
	{
		waitpid(child, &st, 0);
		_farray(cmd), free(ccmd);
	}
	return (WEXITSTATUS(st));
}
