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
    return (mini);
}