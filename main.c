#include "main.h"
/**
* main - Simple Shell main fct
* @argc: argument
* @argv: argument
* Return: 0 Always (success)
*/
int main(int argc, char **argv)
{
	int stat = 0, i = 0;
	char *l = NULL, **cmd = NULL;
	(void) argc;


	while (1)
	{
		l = _readline();
		if (l == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}
		i++;
		cmd = _tkn(l);
		if (!cmd)
			continue;
		if (_ib(cmd[0]))
			_hb(cmd, argv, &stat, i);
		else
			stat = _exec(cmd, argv, i);
	}
}
