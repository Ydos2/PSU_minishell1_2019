/*
** EPITECH PROJECT, 2020
** ls
** File description:
** ls
*/

#ifndef LS_H_
#define LS_H_
#include <stddef.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
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
    int ret_nbr;
    int i;
    int j;
    char **flag;
} mini_t;

// initialise.c
mini_t *initialise_var_start(mini_t *mini);
int set_exit(mini_t *mini, char *line);

// minishell.c
int initialise_minishell(int argc, char **argv, mini_t *mini, char **envp);
int initialise_shell(char **argv, mini_t *mini, char **envp);
int get_argument(mini_t *mini, char *line, char **envp);
void set_other_command(mini_t *mini, char *line, char **envp);
void set_command_not_find(char *line);

// toold_fonction.c
int my_strcmpp(char const *s1, char const *s2);
char *my_len_str(char *str);
int my_putstr(char const *str);
void my_putchar(char c);

// cd.c
int initialise_cd(char *line, char **envp);
char *get_path(char *line);
char *get_cd_solo(char *line, char **envp);

// unix_argument.c
int set_unix(mini_t *mini, char *line, char **envp);
char *get_unix_arg(mini_t *mini, char *line);
void set_binarie(mini_t *mini, char *line, char **envp);

// env.c
char *set_path(char *line, char **envp, mini_t *mini);
char *set_test_path(char **envp, char *line, int k, mini_t *mini);
int initialise_envv(char **envp);

// setenv.c
int initialise_setenvv(char *line);

// unsetenv.c
int initialise_unsetenvv(char *line, char **envp);

// signal.c
void set_signal_Handler(int signalValue);

// my_str_to_word_array.c
char **my_str_to_word_array(char *str);
void my_free_and_set(char **array, int offset, char *to_free);
void my_attribute_line(char *buffer, char **array, int *k, int *array_nb);
int my_strlen_word(char *str, int *cursor);
int my_count_word(char *str);

// my_str_cat_malloc.c
int my_strlen_protect(char *str);
char *my_strcat_malloc(char *dest, char *src);

// my_memset.c
void my_memset(char *buffer, int size);

// clear_str.c
char *my_clear_begin(char *str);
char *my_clear_space(char *str);
char *my_clear_str(char *str);
int my_strlen(char const *str);

#endif /* !LS_H_ */