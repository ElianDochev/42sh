/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** the && and || operators
*/

#include "main.h"

void and_opp(char *args, int *running, env_t **env)
{
    char *arg = parser(&args, 0, sep_opps);

    control_flow(arg, env, running);
    if (find_var(STATUS, *env)->value[0] != '0') {
        add_to_env(env, STATUS, ERR_STATUS, 1);
        return;
    }
    control_flow(args, env, running);
}

void or_opp(char *args, int *running, env_t **env)
{
    char *arg = parser(&args, 0, sep_opps);

    control_flow(arg, env, running);
    if (find_var(STATUS, *env)->value[0] == '0') {
        add_to_env(env, STATUS, SUCCESS_STATUS, 1);
        return;
    }
    control_flow(args, env, running);
}
