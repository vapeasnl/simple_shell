#include "main.h"
/**
* main - Simple Shell main fct
* @argc: argument
* @argv: argument
* Return: 0 Always (success)
*/
int main(int argc, char **argv)
{
	char *l = NULL;
	char **cmd = NULL;
	int stat = 0, index = 0;
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
		index++;

		cmd = tkn(l);
		if (!cmd)
			continue;

		if (_ib(cmd[0]))
			_hb(cmd, argv, &stat, index);
		else
			stat = _exec(cmd, argv, index);
	}
}
