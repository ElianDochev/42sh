/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** command setenv and unsetenv
*/

#include "main.h"

void my_setenv(char *args, env_t **env)
{

}

void my_unsetenv(char *args, env_t **env)
{

}

void print_env(char *args, env_t **env)
{
    env_t *tmp = *env;

    for (; tmp != NULL; tmp = tmp->next)
        my_printf("%s=%s\n", tmp->var, tmp->value);
}