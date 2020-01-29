/*
** EPITECH PROJECT, 2019
** criterion
** File description:
** criterion
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(set_line_formatting, line_formatting_0, .timeout = 1)
{
    int return_value = 0;

    return_value = set_line_formatting("cd");
    cr_assert_eq(return_value, 0);
}

Test(set_line_formatting, line_formatting_1, .timeout = 1)
{
    int return_value = 0;

    return_value = set_line_formatting("    \tcd");
    cr_assert_eq(return_value, 4);
}