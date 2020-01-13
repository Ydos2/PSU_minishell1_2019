/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"
#include "minishell.h"

int cd(char *line)
{
    char *path;

    path = get_path(line);
    return (1);
}

char *get_path(char *line)
{
    char *path;
    int i = 0, z = 0;

    for (; line[z] != '\0'; z++)
        if (line[i] != ' ')
            i++;
    i = i - 2;
    path = malloc(sizeof(char) * i);
    for (int j = 0, k = 2; k != z; k++)
        if (line[k] != ' ') {
            path[j] = line[k];
            j++;
        }
    return (path);
}