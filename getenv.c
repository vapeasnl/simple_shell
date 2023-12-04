#include "main.h"
/**
* _getenv --
* @var: --
* Return: --
*/
char *_getenv(char *var)
{
	char *tmp, *key, *val, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _stdrup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, var) == 0)
		{
			val = strtok(NULL, "\n");
			env = _stdrup(val);
			free(tmp);
			return (val);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
