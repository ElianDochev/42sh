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
    new->malloced = 0;
    return (new);
}

static void set_malloc(env_t *env, int overwrite, int call)
{
    if (call > 0) {
        CHK_FLAG(env->malloced, FREE_VALUE) ? free(env->value),
        UNSET_FLAG(env->malloced, FREE_VALUE) : 0;
    }
    if (overwrite - 1 >= 1) {
        SET_FLAG(env->malloced, FREE_VALUE);
    }
    if (overwrite - 2 >= 1) {
        SET_FLAG(env->malloced, FREE_VAR);
    }
}

int add_to_env(env_t **env, char *var, char *value, int overwrite)
{
    env_t *tmp = NULL;

    if ((tmp = find_var(var, *env)) != NULL)
        if (overwrite == 0)
            return (1);
        else {
            set_malloc(tmp, MIN(overwrite, 2), 1);
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
    set_malloc(tmp->next, overwrite, 0);
    return 0;
}

static void handle_mask(env_t *env)
{
    if (CHK_FLAG(env->malloced, FREE_VAR))
        free(env->var);
    if (CHK_FLAG(env->malloced, FREE_VALUE))
        free(env->value);
}

void remove_from_env(env_t **env, char *var)
{
    env_t *tmp = *env;
    env_t *prev = NULL;

    while (tmp != NULL && str_cmp(tmp->var, var) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    if (prev == NULL) {
        *env = tmp->next;
        handle_mask(tmp);
        free(tmp);
        return;
    } else {
        prev->next = tmp->next;
        handle_mask(tmp);
        free(tmp);
        return;
    }
}
