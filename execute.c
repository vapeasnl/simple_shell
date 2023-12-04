#include "main.h"
/**
* _execute --
* @cmd: --
* @argv: --
* @index: --
* Return: --
*/
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
		if (execve(full_cmd, cmd, environ) == -1)
		{
			free(full_cmd);
			freearray(cmd);
		}
	}
	else
	{
		waitpid(child, &stat, 0);
		freearray(cmd);
		free(full_cmd);
	}
	return (WEXITSTATUS(stat));
}
