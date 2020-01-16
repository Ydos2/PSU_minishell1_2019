/*
** EPITECH PROJECT, 2020
** signal
** File description:
** signal
*/

#include "my.h"
#include "minishell.h"

void signalHandler(int signalValue)
{
    write(1, "\n▀▄▀▄▀▄ Minishell ▄▀▄▀▄▀$> ", 51);
}