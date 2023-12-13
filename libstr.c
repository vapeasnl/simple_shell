#include "main.h"
/**
* _cpy Copy the contents of one string to another
* @dest: Destination string
* @src: Source string
* Return: The destination string after copying
*/
char *_cpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
* _dup Duplicate a string
* @str: Null-terminated string to be duplicated
* Return: A dynamically allocated string containing the duplicated content,
* or NULL if the input string is NULL or if memory allocation fails
*/
char *_dup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}
/**
* _cat Concatenate two strings
* @dest: Destination string
* @src: Source string
* Return: The destination string after concatenation
*/
char *_cat(char *dest, char *src)
{
	char *p = dest;

	while (*p)
		p++;

	while (*src)
	{
		*p = *src;
		p++;
		src++;
	}
	*p = *src;
	return (dest);
}
/**
* _cmp Compare two strings lexicographically
* @s1: First string for comparison
* @s2: Second string for comparison
* Return: An integer less than, equal to, or greater than zero if the first
* string is lexicographically less than, equal to, or greater than
* the second string, respectively
*/
int _cmp(char *s1, char *s2)
{
	int cmp;

	cmp = (int)*s1 - (int)*s2;
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
		cmp = (int)*s1 - (int)*s2;
	}
	return (cmp);
}
/**
* _len Calculate the length of a null-terminated string
* @s: Null-terminated string for which to calculate the length.
* Return: The length of the string
*/
int _len(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}
