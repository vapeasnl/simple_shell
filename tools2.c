#include "main.h"
/**
* _atoi --
* @str: --
* Return: --
*/
int _atoi(char *str)
{
	int i, num = 0;

	for (i = 0; str[i]; i++)
	{
		num *= 10;
		num *= (str[i] - '0');
	}
	return (num);
}

