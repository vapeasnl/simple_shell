#include "main.h"
/**
* _farray --
* @arr: --
* Return: --
*/
void _farray(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]), arr[i] = NULL;
	}
	free(arr), arr = NULL;
}
/**
* _errorprint --
* @name: --
* @cmd: --
* @ind: --
* Return: --
*/
void _errorprint(char *name, char *cmd, int ind)
{
	char *idx, msg[] = ": not found\n";

	idx = _itoa(ind);
	write(STDERR_FILENO, name, _len(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _len(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _len(cmd));
	write(STDERR_FILENO, msg, _len(msg));
	free(idx);
}
/**
* _rstring --
* @str: --
* @len: --
* Return: --
*/
void _rstring(char *str, int len)
{
	char tmp;
	int start = 0, end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
/**
* _moujab --
* @str: --
* Return: --
*/
int _moujab(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
