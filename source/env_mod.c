/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** command setenv and unsetenv
*/

#include "main.h"

env_t *find_var(char *var, env_t *env)
{
    for (int i = 0; env != NULL; env = env->next, ++i)
        if (str_cmp(env->var, var) == 0)
            return (env);
    return (NULL);
}

static int sep_eq(char c)
{
    if (c == '=')
        return 0;
    return 1;
}

void my_setenv(char *args, env_t **env)
{
    char *var = NULL;
    char *value = NULL;

    remove_sep(&args, sep_sp_tab, 0);
    var = parser(&args, 1, sep_sp_tab_rev);
    parser(&args, 0, sep_sp_tab_rev);
    for (int i = 0; var[i] != '\0'; ++i) {
        if (var[i] == '=' && var[i + 1] != '\0') {
            break;
        }
        if (var[i] != '=' && var[i + 1] != '\0') {
            continue;
        }
        add_to_env(env, STATUS, ERR_STATUS, 1);
        return;
    }
    value = parser(&var, 1, sep_eq);
    add_to_env(env, my_strdup(var), my_strdup(value), 3);
    add_to_env(env, STATUS, SUCCESS_STATUS, 1);
}

void my_unsetenv(char *args, env_t **env)
{
    char *var = NULL;

    remove_sep(&args, sep_sp_tab_rev, 0);
    var = parser(&args, 1, sep_sp_tab_rev);
    parser(&args, 0, sep_sp_tab_rev);
    if (find_var(var, *env) == NULL) {
        add_to_env(env, STATUS, ERR_STATUS, 1);
        return;
    }
    remove_from_env(env, var);
    add_to_env(env, STATUS, SUCCESS_STATUS, 1);
}
