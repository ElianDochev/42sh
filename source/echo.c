/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** the echo command
*/

#include "main.h"

void echo(char *args, env_t **env)
{
    char *tmp = NULL;
    env_t *tmp_env = NULL;

    remove_sep(&args, sep_sp_tab, 0);
    tmp = parser(&args, 1, sep_sp_tab);
    parser(&args, 0, sep_sp_tab); // under question
    if (str_cmp(tmp, "$?") == 0) {
        tmp_env = find_var("STATUS", *env);
        my_printf("%s\n", tmp_env->value);
    } else {
        my_printf("%s\n", tmp);
    }
}