#include "shell.h"
char *_getpath(char *cmd)
{
    char *path_env, *full_cmd, *dir;
    int i;
    struct stat status;

    for (i = 0; cmd[i]; i++)
    {
        if (cmd[i] == '/')
        {
            if (stat(cmd, &status) == 0)
                return (_stdrup(cmd));
            return (NULL);
        }
    }

    path_env = _getenv("PATH");
    if (!path_env)
        return(NULL);

    dir = strtok(path_env, ":")
    while (dir)
    {

        full_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
        if (full_cmd)
        {
            _strcpy(full_cmd, dir);
            _strcat(full_cmd, "/");
            _strcat(full_cmd, cmd);
            if (stat(full_cmd, &status) == 0)
            {
                free(path_env);
                return (full_cmd);

            }
            free(full_cmd), full_cmd = NULL;

            dir = strtok(NULL, ":");
        }
    }
    free(path_env);
    return (NULL);
}
