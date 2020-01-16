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
    signal(SIGINT, signalHandler);

    while (mini->quit == 0) {
        shell(argv, mini, envp);
    }
    return (0);
}

int shell(char **argv, mini_t *mini, char **envp)
{
    char *line;
    size_t len = 0;

    write(1, "▀▄▀▄▀▄ Minishell ▄▀▄▀▄▀$> ", 50);
    if (getline(&line, &len, stdin) == -1) {
        mini->quit = 1;
        return (0);
    }
    line = len_str(line);
    get_argument(mini, line, envp);
    return (0);
}

int get_argument(mini_t *mini, char *line, char **envp)
{
    int i = 0;

    if ((my_strcmpp(line, "exit")) == 0)
        mini->quit = 1, i = 1;
    if (line[0] == 'c' && line[1] == 'd')
        i = cd(line, envp);
    if ((my_strcmpp(line, "setenv")) == 0)
        i = setenvv(line);
    if ((my_strcmpp(line, "unsetenv")) == 0)
        i = unsetenvv(line);
    if ((my_strcmpp(line, "env")) == 0)
        i = envv(envp);
    if (i == 1)
        return (0);
    set_other_command(mini, line, envp);
    return (0);
}

void set_other_command(mini_t *mini, char *line, char **envp)
{
    char *path = NULL;

    mini->flag = my_str_to_word_array(line);
    line = get_unix_arg(mini, line);
    path = set_path(line, envp, mini);
    if (path != NULL)
        set_unix(mini, path, envp);
    else
        set_command_not_find(line);
}

void set_command_not_find(char *line)
{
    my_putstr(line);
    write(1, ": Command not found.\n", 21);
}