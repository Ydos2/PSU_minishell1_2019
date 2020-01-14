/*
** EPITECH PROJECT, 2020
** ls
** File description:
** ls
*/

#ifndef LS_H_
#define LS_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

typedef struct mini
{
    int quit;
} mini_t;

// initialise.c
mini_t *initialise_var_start(mini_t *mini);

// minishell.c
int minishell(int argc, char **argv, mini_t *mini, char **envp);
int shell(char **argv, mini_t *mini, char **envp);
int get_argument(mini_t *mini, char *line, char **envp);

// toold_fonction.c
int my_strcmpp(char const *s1, char const *s2);
char *len_str(char *str);

// cd.c
int cd(char *line);
char *get_path(char *line);

// unix_argument.c
int set_unix(mini_t *mini, char *line, char **envp);

// env.c
char *set_path(char *line, char **envp);
int envv(char *line);

// setenv.c
int setenvv(char *line);

// unsetenv.c
int unsetenvv(char *line);

// my_str_to_wordtab.c
int count_word(char *str);
int countchar(char *str);
char **my_str_to_wordtab(char *str);

#endif /* !LS_H_ */