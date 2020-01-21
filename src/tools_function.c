/*
** EPITECH PROJECT, 2020
** tools_function
** File description:
** tools_function
*/

#include "minishell.h"

int my_strcmpp(char const *s1, char const *s2)
{
    int i = 0;

    while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
        i++;
    if (s1[i] < s2[i])
        return (-1);
    else if (s2[i] < s1[i])
        return (1);
    else
        return (0);
}

char *my_len_str(char *str)
{
    char *len_str;
    int i = 0;

    for (; str[i] != '\0'; i++);
    len_str = malloc(sizeof(char) * i);
    for (int j = 0; j != i-1; j++)
        len_str[j] = str[j];
    return (len_str);
}

int my_putstr(char const *str)
{
    char i = 0;

    for (; str[i] != '\0'; i++)
        my_putchar(str[i]);
    return (0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}