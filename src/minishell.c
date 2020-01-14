/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** minishell
*/

#include "my.h"
#include "minishell.h"

int minishell(int argc, char **argv, mini_t *mini, char **envp)
{
    while (mini->quit == 0) {
        shell(argv, mini, envp);
    }
    return (0);
}

int shell(char **argv, mini_t *mini, char **envp)
{
    char *line;
    size_t len = 0;

    getline(&line, &len, stdin);
    line = len_str(line);
    get_argument(mini, line, envp);
    return (0);
}

int get_argument(mini_t *mini, char *line, char **envp)
{
    char *path = NULL;
    int i = 0;

    if ((my_strcmpp(line, "exit")) == 0)
        mini->quit = 1, i = 1;
    if (line[0] == 'c' && line[1] == 'd')
        i = cd(line);
    if ((my_strcmpp(line, "setenv")) == 0)
        i = setenvv(line);
    if ((my_strcmpp(line, "unsetenv")) == 0)
        i = unsetenvv(line);
    if ((my_strcmpp(line, "env")) == 0)
        i = envv(line);
    if (i == 1)
        return (0);
    path = set_path(line, envp);
    set_unix(mini, path, envp);
    return (0);
}