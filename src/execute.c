/*
** EPITECH PROJECT, 2020
** execute
** File description:
** execute
*/

#include "minishell.h"

int set_ex(mini_t *mini, char *line)
{
    char *path = NULL;
    int nbr = 0;

    for (int i = 2; line[i] != '\0'; i++, nbr++)
        if (line[i] == ' ')
            break;
    path = malloc(sizeof(char) * nbr);
    for (int i = 0, j = 2; nbr != 0; i++, j++, nbr--)
        path[i] = line[j];
    mini->flag = my_str_to_word_array(line);
    initialise_ex(mini, path);
    return (1);
}

void initialise_ex(mini_t *mini, char *path)
{
    pid_t pid = 0;
    pid_t j = 0;
    int arg = 0;

    pid = fork();
    if (pid == 0)
        execve(path, mini->flag, mini->envp);
    else if (pid > 0)
        j = waitpid(pid, &arg, 0);
    if (WIFSIGNALED(arg)) {
        my_putstr(strsignal(WTERMSIG(arg)));
        write(1, " (core dumped)\n", 15);
    }
    kill(pid, SIGKILL);
}