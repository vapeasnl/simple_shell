#include "main.h"
/**
* _atoi --
* @str: --
* Return: --
*/
int _atoi(char *str)
{
	int i, n = 0;

	for (i = 0; str[i]; i++)
	{
		n *= 10;
		n += (str[i] - '0');
	}
	return (n);
}
/**
* _itoa --
* @n: --
* Return: --
*/
char *_itoa(int n)
{
	char buffer[25];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	_rstring(buffer, i);
	return (_dup(buffer));

}
