#include "main.h"
/**
* _getpath --
* @cmd: --
* Return: --
*/
char *_getpath(char *cmd)
{
	char *path_env, *full_cmd, *dir;
	int i;
	struct stat status;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &status) == 0)
			return (_dup(cmd));
			return (NULL);
		}
	}

	path_env = _getenv("PATH");
	if (!path_env)
		return (NULL);

	dir = strtok(path_env, ":");
	while (dir)
	{

		full_cmd = malloc(_len(dir) + _len(cmd) + 2);
		if (full_cmd)
		{
			_cpy(full_cmd, dir);
			_cat(full_cmd, "/");
			_cat(full_cmd, cmd);
			if (stat(full_cmd, &status) == 0)
			{
			free(path_env);
			return (full_cmd);
			}
			free(full_cmd), full_cmd = NULL;
			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
/**
* _getenv --
* @var: --
* Return: --
*/
char *_getenv(char *var)
{
	char *tmp, *key, *val, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _dup(environ[i]);
		key = strtok(tmp, "=");
		if (_cmp(key, var) == 0)
		{
			val = strtok(NULL, "\n");
			env = _dup(val);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
/**
* _readline --
* Return: --
*/
char *_readline(void)
{
	char *l = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
	n = getline(&l, &len, stdin);
	if (n == -1)
	{
		free(l);
		return (NULL);
	}
	return (l);
}
