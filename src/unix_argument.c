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
    int arg = 0;

    pid = fork();
    if (pid == 0)
        execve(path, mini->flag, envp);
    else if (pid > 0)
        j = waitpid(pid, &arg, 0);
    if (WIFSIGNALED(arg))
        my_putstr(strsignal(WTERMSIG(arg)));
    kill(pid, SIGKILL);
    return (0);
}

char *get_unix_arg(mini_t *mini, char *line)
{
    char *arg_line = NULL;
    int i = 0;
    int j = 0;

    for (i = 0; line[i] != '\0'; i++);
    arg_line = malloc(sizeof(char) * i);
    for (j = 0; line[j] != '\0'; j++) {
        if (line[j] == ' ')
            break;
        arg_line[j] = line[j];
    }
    return (arg_line);
}