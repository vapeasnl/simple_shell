#include "main.h"
/**
* freearray --
* @arr: --
* Return: --
*/
void freearray(char **arr)
{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr), arr = NULL;
}
/**
* printerror --
* @name: --
* @cmd: --
* @index: --
* Return: --
*/
void printerror(char *name, char *cmd, int index)
{
	char *idx, msg[] = ": not found\n";

	idx = _itoa(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(idx);


}
/**
* reverse_string --
* @str: --
* @lenght: --
* Return: --
*/
void reverse_string(char *str, int lenght)
{
	char tmp;
	int start = 0;
	int end = lenght - 1;

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
* _itoa --
* @n: --
* Return: --
*/
char *_itoa(int n)
{
	char buff[25];
	int i = 0;

	if (n == 0)
		buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buff[i] = '\0';
	reverse_string(buff, i);

	return (_strdup(buff));

}
/**
* is_positive_number --
* @str: --
* Return: --
*/
int is_positive_number(char *str)
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
