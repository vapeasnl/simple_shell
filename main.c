#include "shell.h"
/**
* main - Simple Shell main fct
* @argc: argument
* @argv: argument
* Return: 0 Always (success)
*/
int main(int argc, char **argv)
{
    char *l = NULL;
    char ** cmd = NULL;
    int stat, index = 0;
    (void) argc;


    while (1)
    {
        l = read_line();
        if (l == NULL)
        {
            if (isatty(STDIN_FILENO))
                write(STDOUT_FILENO, "\n", 1);
            return (stat);
        }
        index++;
        
        cmd = tokenizer(l);
        if (!cmd)
            continue;
        
        stat = _execute(cmd, argv, index);
    }


}
