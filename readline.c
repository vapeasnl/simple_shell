#include "main.h"
/**
* read_line --
* Return: --
*/
char *read_line(void)
{
	char *l = NULL;
	size_t lenght = 0;
	ssize_t n;


	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "$ ", 2);
	n = getline(&l, &lenght, stdin);
	if (n == -1)
	{
		free(l);
		return (NULL);
	}


	return (l);
}
