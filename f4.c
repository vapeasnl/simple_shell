#include "main.h"
/**
 * _ib - Check if a command is a built-in command
 * @cmd: Command to be checked
 * Return: 1 if the command is a built-in command, 0 otherwise
 */
int _ib(char *cmd)
{
	char *built_in[] = {
		"exit", "env", "setenv",
		"cd", NULL
	};
	int i;

	for (i = 0; built_in[i]; i++)
	{
		if (_cmp(cmd, built_in[i]) == 0)
			return (1);
	}
	return (0);
}
/**
 * _hb - Handle built-in commands
 * @cmd: Array of strings representing the command and its arguments
 * @argv: Array of strings representing the program and its arguments
 * @st: Pointer to the exit status
 * @ind: Index of the command in the argv array
 * Return: None
 */
void _hb(char **cmd, char **argv, int *st, int ind)
{
	if (_cmp(cmd[0], "exit") == 0)
	_exit_sh(cmd, argv, st, ind);

	else if (_cmp(cmd[0], "env") == 0)
		_printenv(cmd, st);
}
/**
 * _exit_sh - Handle the "exit" built-in command
 * @cmd: Array of strings representing the command and its arguments.
 * @argv: Array of strings representing the program and its arguments
 * @st: Pointer to the exit status
 * @ind: Index of the command in the argv array
 * Return: None
 */
void _exit_sh(char **cmd, char **argv, int *st, int ind)
{
	int exit_v = (*st);
	char *idx, msg[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (_moujab(cmd[1]))
		{
			exit_v = _atoi(cmd[1]);
		}
		else
		{
			idx = _itoa(ind);
			write(STDERR_FILENO, argv[0], _len(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idx, _len(idx));
			write(STDERR_FILENO, msg, _len(msg));
			write(STDERR_FILENO, cmd[1], _len(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx);
			_farray(cmd);
			(*st) = 2;
			return;
		}
	}
	_farray(cmd);
	exit(exit_v);
}
/**
 * _printenv - Handle the "env" built-in command
 * @cmd: Array of strings representing the command and its arguments
 * @st: Pointer to the exit statu
 * Return: None
 */
void _printenv(char **cmd, int *st)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _len(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	_farray(cmd);
	(*st) = 0;
}
