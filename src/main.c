/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    mini_t *mini = NULL;

    if (argc != 1)
        return (84);
    mini = initialise_var_start(mini);
    if (initialise_minishell(argc, argv, mini, envp) == 84)
        return (84);
    write(1, "exit\n", 5);
    return (mini->ret_nbr);
}