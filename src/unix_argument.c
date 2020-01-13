/*
** EPITECH PROJECT, 2020
** unix_argument
** File description:
** unix_argument
*/

#include "my.h"
#include "minishell.h"

int set_unix(mini_t *mini, char *path, char **envp)
{
    pid_t pid = 0;
    pid_t j = 0;
    char *newargv[] = { "-l", NULL };
    int arg = 0;

    pid = fork();
    if (pid == 0)
        execve(path, newargv, envp);
    else if (pid > 0)
        j = waitpid(pid, &arg, 0);
    kill(pid, SIGKILL);
    return (0);
}