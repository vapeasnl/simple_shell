#include "main.h"
/**
 * _tkn - Tokenize a line into an array of strings
 * @l: Line of input to be tokenized
 * Return: An array of strings representing the tokens, or NULL on failure
 */
char **_tkn(char *l)
{
	int cnt = 0, i = 0;
	char *tkn = NULL, *tmp = NULL, **cmd = NULL;

	if (!l)
		return (NULL);
	tmp = _dup(l);
	tkn = strtok(tmp, DELIM);
	if (tkn == NULL)
	{
		free(l), l = NULL;
		free(tmp), tmp = NULL;
		return (NULL);

	}
	while (tkn)
	{
		cnt++;
		tkn = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (cnt + 1));
	if (!cmd)
	{
		free(l);
		return (NULL);
	}
	tkn = strtok(l, DELIM);
	while (tkn)
	{
		cmd[i] = _dup(tkn);
		tkn = strtok(NULL, DELIM);
		i++;
	}
	free(l), l = NULL;
	cmd[i] = NULL;
	return (cmd);
}

