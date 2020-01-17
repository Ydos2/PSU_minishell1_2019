/*
** EPITECH PROJECT, 2020
** clear_str
** File description:
** clear_str
*/

#include "my.h"
#include "minishell.h"

char *clear_begin(char *str)
{
    int i = 0;

    while (str && str[i]) {
        if (str[i] != ' ')
            return &str[i];
        i++;
    }
}

char *clear_space(char *str)
{
    int i = 0;
    int j = 0;
    int spaced = 0;
    char *clear = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str && str[i]) {
        if (str[i] != ' ') {
            clear[j] = str[i];
            j++;
            spaced = 0;
        } else if (spaced == 0 && str[i] == ' ') {
            spaced = 1;
            clear[j] = ' ';
            j++;
        }
        i++;
    }
    clear[j] = '\0';
    return (clear);
}

char *clear_str(char *str)
{
    int i = 0;
    char *clear;

    while (str && str[i]) {
        if (str[i] == '\t')
            str[i] = ' ';
        i++;
    }
    str = clear_begin(str);
    clear = clear_space(str);
    return (clear);
}

int my_strlen(char const *str)
{
    char i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}