/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"
#include "minishell.h"

int initialise_cd(char *line, char **envp)
{
    int a = 0;
    char *path;

    if (line[3] == '\0')
        path = get_cd_solo(line, envp);
    else
        path = get_path(line);
    a = chdir(path);
    if (a == -1) {
        my_putstr(path);
        write(1, ": No such file or directory.\n", 29);
    }
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

char *get_cd_solo(char *line, char **envp)
{
    char *path;
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; envp[i] != NULL; i++) {
        if (envp[i][0] == 'H' && envp[i][1] == 'O' &&
        envp[i][2] == 'M' && envp[i][3] == 'E' &&
        envp[i][4] == '=')
            break;
    }
    for (j = 0; envp[i][j] != '\0'; j++);
    path = malloc(sizeof(char) * j);
    for (j = 0, k = 5; envp[i][k] != '\0'; j++, k++)
        path[j] = envp[i][k];
    return (path);
}