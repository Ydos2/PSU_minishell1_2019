/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** minishell
*/

#include "minishell.h"

int initialise_minishell(int argc, char **argv, mini_t *mini, char **envp)
{
    signal(SIGINT, set_signal_Handler);
    mini->envp = envp;

    while (1) {
        initialise_shell(argv, mini);
        if (mini->quit != 0)
            break;
    }
    return (0);
}

int initialise_shell(char **argv, mini_t *mini)
{
    char *line = NULL;
    size_t len = 0;
    int get = 0;

    write(1, "▀▄▀▄▀▄ Minishell ▄▀▄▀▄▀$> ", 50);
    get = getline(&line, &len, stdin);
    if (get == -1) {
        write(1, "\n", 1);
        mini->quit = 1;
        free(line);
        return (0);
    } else if (get < -1) {
        free(line);
        return (0);
    }
    line = my_len_str(line);
    get_argument(mini, line);
    free(line);
    return (0);
}

int get_argument(mini_t *mini, char *line)
{
    int i = 0;

    if (line[0] == 'e' && line[1] == 'x' &&
    line[2] == 'i' && line[3] == 't')
        i = set_exit(mini, line);
    if (line[0] == 'c' && line[1] == 'd')
        if (line[2] == ' ' || line[2] == '\0')
            i = initialise_cd(line, mini->envp);
    if (line[0] == 's' && line[1] == 'e' && line[2] == 't'
        && line[3] == 'e' && line[4] == 'n' && line[5] == 'v')
        i = initialise_setenvv(line, mini);
    if (line[0] == 'u' && line[1] == 'n' && line[2] == 's'
    && line[3] == 'e' && line[4] == 't' && line[5] == 'e'
    && line[6] == 'n' && line[7] == 'v')
        i = initialise_unsetenvv(line, mini->envp, mini);
    if ((my_strcmpp(line, "env")) == 0)
        i = initialise_envv(mini->envp);
    if (i == 1)
        return (0);
    set_other_command(mini, line, mini->envp);
    return (0);
}

void set_other_command(mini_t *mini, char *line, char **envp)
{
    char *path = NULL;

    if (line[0] == '.' && line[1] == '/') {
        path = set_path(line, envp, mini);
        set_binarie(mini, path, envp);
    } else if (line[0] != '\0') {
        mini->flag = my_str_to_word_array(line);
        line = get_unix_arg(mini, line);
        path = set_path(line, envp, mini);
        if (path != NULL)
            set_unix(mini, path, envp);
        else
            set_command_not_find(line);
    }
}

void set_command_not_find(char *line)
{
    my_putstr(line);
    write(1, ": Command not found.\n", 21);
}