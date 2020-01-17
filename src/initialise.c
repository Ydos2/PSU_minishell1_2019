/*
** EPITECH PROJECT, 2020
** initialise
** File description:
** initialise
*/

#include "my.h"
#include "minishell.h"

mini_t *initialise_var_start(mini_t *mini)
{
    mini = malloc(sizeof(mini_t));
    mini->quit = 0;
    mini->ret_nbr = 0;
    return (mini);
}

int set_exit(mini_t *mini, char *line)
{
    char **flag = my_str_to_word_array(line);
    int nbr = 1;
    int actu_nbr = 0;

    mini->quit = 1;
    for (int i = 0; flag[1][i+1] != '\0'; nbr = nbr * 10, i++);
    for (int i = 0, j = nbr; flag[1][i] != '\0'; i++) {
        actu_nbr = (flag[1][i] - 48) * j;
        mini->ret_nbr += actu_nbr;
        j = j / 10;
    }
    return (1);
}