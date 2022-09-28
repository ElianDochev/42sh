/*
** EPITECH PROJECT, 2022
** 42sg
** File description:
** convetring the char ** to linked list
*/

#include "main.h"

static env_t *insert_env_var(char *var, char *value)
{
    env_t *new = malloc(sizeof(env_t));

    new->var = var;
    new->value = value;
    new->next = NULL;
    return (new);
}

env_t *find_var(char *var, env_t *env)
{
    for (int i = 0; env != NULL; env = env->next, ++i)
        if (str_cmp(env->var, var) == 0)
            return (env);
    return (NULL);
}

int add_to_env(env_t **env, char *var, char *value, int overwrite)
{
    env_t *tmp = NULL;

    if ((tmp = find_var(var, *env)) != NULL)
        if (overwrite == 0)
            return (1);
        else {
            tmp->value = value;
            return (0);
        }
    if (*env == NULL) {
        *env = insert_env_var(var, value);
        return 0;
    }
    tmp = *env;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = insert_env_var(var, value);
    return 0;
}

void remove_from_env(env_t **env, char *var)
{
    env_t *tmp = *env;
    env_t *prev = NULL;

    while (tmp!= NULL && str_cmp(tmp->var, var) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    if (prev == NULL) {
        *env = tmp->next;
        free(tmp);
        return;
    } else {
        prev->next = tmp->next;
        free(tmp);
        return;
    }
}
