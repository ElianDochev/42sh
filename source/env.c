/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** command setenv and unsetenv
*/

#include "main.h"

void print_env(char *args, char ***env)
{
    for (int i = 0; (*env)[i] != NULL; i++)
        my_printf("%s\n", (*env)[i]);
}

static void add_to_env(char ***env, char *args)
{
    char **tmp = malloc(sizeof(char *) * (get_len_two_d(*env) + 2));

    for (int i = 0; (*env)[i] != NULL; ++i)
        tmp[i] = (*env)[i];
    tmp[get_len_two_d(*env)] = args;
    tmp[get_len_two_d(*env) + 1] = NULL;
    free(*env);
    *env = tmp;
}

void my_setenv(char *args, char ***env)
{
    char **arg = split_str(args, sep_sp_tab);
    char *tmp = NULL;
    char *tmp_two = NULL;
    char tmp_three[64];

    if (arg[1] == NULL || arg[2] == NULL) {
        error("setenv: Too few arguments.\n");
        delete_two_d_string(arg);
        return;
    }
    tmp = str_join(arg[1], "=");
    tmp_two = tmp;
    tmp = str_join(tmp, arg[2]);
    free(tmp_two);
    str_in_word_arr(tmp_three, *env, tmp) == 0 ?
    error("Error var already exists\n") : add_to_env(env, tmp);
    delete_two_d_string(arg);
}

static void remove_from_env(char ***env, char *args)
{
    char **tmp = malloc(sizeof(char *) * (get_len_two_d(*env)));
    int i = 0;
    int offset = 0;

    for (; (*env)[i + offset] != NULL; ++i) {
        if (str_ncmp((*env)[i], args, my_strlen(args)) != 0) {
            tmp[i] = (*env)[i + offset];
        } else
            ++offset;
    }
    tmp[i] = NULL;
    free(*env);
    *env = tmp;
}

void my_unsetenv(char *args, char ***env)
{
    char **arg = split_str(args, sep_sp_tab);
    char tmp_three[64];

    if (arg[1] == NULL) {
        error("unsetenv: Too few arguments.\n");
        return;
    }
    if (get_len_two_d(arg) > 2) {
        error("unsetenv: Too many arguments.\n");
        return;
    }
    str_in_word_arr(tmp_three, *env, arg[1]) == 1 ?
    error("Error var doesn't exist\n") : remove_from_env(env, arg[1]);
    delete_two_d_string(arg);
}
