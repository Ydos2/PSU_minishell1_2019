/*
** EPITECH PROJECT, 2020
** unsetenv
** File description:
** unsetenv
*/

#include "minishell.h"

int initialise_unsetenvv(char *line, char **envp)
{
    int y = 0;
    int line_int = 0;

    for (int j = 0; line[j] != '\0'; y++, j++);
    for (int i = 0; envp[i] != NULL; i++) {
        for (int j = 0; envp[i][j] == line[j]; j++)
            if (j == y) {
                line_int = i;
                break;
            }
    }
    return (1);
}