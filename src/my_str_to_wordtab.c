/*
** EPITECH PROJECT, 2020
** my_str_to_wordtab
** File description:
** my_str_to_wordtab
*/

#include "my.h"
#include "minishell.h"

int count_word(char *str)
{
    int i = 0;
    int n = 1;

    for (; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == ' ' && str[i + 1] != '\0')
            n++;
    }
    return (n);
}

int countchar(char *str)
{
    int c = 0;

    while ((str[c] != ' ') && (str[c] != '\0') && (str[c] != '\n'))
        c++;
    c++;
    return (c);
}

char **my_str_to_wordtab(char *str)
{
    char **tab;
    int i = 0;
    int b = 0;
    int a = 0;

    tab = malloc(sizeof(*tab) * ((count_word(str) + 1)));
    while (str[i] != '\t' && str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\n') {
            for (; str[i] == ' '; i++);
            a++;
            b = 0;
        }
        tab[a] = malloc(sizeof(**tab) * ((countchar(str + i) + 1)));
        while ((str[i] != ' ')  && (str[i] != '\n') && (str[i] != '\0'))
        tab[a][b++] = str[i++];
        tab[a][b] = '\0';
    }
    tab[a + 1] = 0;
    return (tab);
}