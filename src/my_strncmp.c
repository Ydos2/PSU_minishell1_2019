/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** my_strncmp
*/

int my_strncmp(char *s1, char *s2, int n, int space)
{
    int x = 0;
    int y = 0;

    for (int j = 0; j < n; j++) {
        if (s1[x+space] == s2[y]) {
            x++;
            y++;
        }
    }
    return (x == n ? 0 : 1);
}