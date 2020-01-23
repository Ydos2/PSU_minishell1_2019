/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** minishell
*/

#include "minishell.h"

int initialise_minishell(mini_t *mini, char **envp)
{
    signal(SIGINT, set_signal_Handler);
    mini->envp = envp;

    while (1) {
        initialise_shell(mini);
        if (mini->quit != 0)
            break;
    }
    return (0);
}

int initialise_shell(mini_t *mini)
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
    int space = set_line_formatting(line);

    if (line[space+0] == '.' && line[space+1] == '/')
        i = set_ex(mini, line, space);
    if ((line[space+0] == 'e' && line[space+1] == 'x' &&
    line[space+2] == 'i' && line[space+3] == 't') && (line[space+4] == ' '
    || line[space+4] == '\0'))
        i = set_exit(mini, line);
    if ((line[space+0] == 'c' && line[space+1] == 'd') &&
    (line[space+2] == ' ' || line[space+2] == '\0'))
        i = initialise_cd(line, mini->envp, space);
    if (line[space+0] == 's' && line[space+1] == 'e' && line[space+2] == 't' &&
    line[space+3] == 'e' && line[space+4] == 'n' && line[space+5] == 'v' &&
    line[space+6] == ' ')
        i = initialise_setenvv(line, mini);
    if (line[space+0] == 'u' && line[space+1] == 'n' && line[space+2] == 's'
    && line[space+3] == 'e' && line[space+4] == 't' && line[space+5] == 'e'
    && line[space+6] == 'n' && line[space+7] == 'v' && line[space+8] == ' ')
        i = initialise_unsetenvv(line, mini->envp, mini);
    if (line[space+0] == 'e' && line[space+1] == 'n' && line[space+2] == 'v')
        i = initialise_envv(mini->envp);
    if (i == 1)
        return (0);
    set_other_command(mini, line, mini->envp, space);
    return (0);
}

void set_other_command(mini_t *mini, char *line, char **envp, int space)
{
    char *path = NULL;

    mini->space = space;
    if (line[space+0] != '\0') {
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