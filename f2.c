#include "main.h"
/**
 * _atoi - Convert a string of digits to an integer
 * @str: String of digits to be converted
 * Return: The integer value of the converted string
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
 * _itoa - Convert an integer to a string
 * @n: Integer to be converted
 * Return: A dynamically allocated string containing the integer
 */
char *_itoa(int n)
{
	char tmp[25];
	int i = 0;

	if (n == 0)
		tmp[i++] = '0';
	else
	{
		while (n > 0)
		{
			tmp[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	tmp[i] = '\0';
	_rstring(tmp, i);
	return (_dup(tmp));

}
