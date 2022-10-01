/*
** EPITECH PROJECT, 2022
** mini_shell 2
** File description:
** parcer for < <<
*/

#include "main.h"

static int get_sep_offset(char * args, int (*sep)(char))
{
    int offset = -1;

    for (int i = 0; args[i]; i++) {
        if (sep(args[i])) {
            offset = i;
            break;
        }
    }
    return (offset);
}

static char * alt_parce(char **args)
{
    int offset = get_sep_offset(*args, sep_sp_tab);
    char *arg_two = *args;

    while (sep_sp_tab((*args)[offset])) {
        (*args)[offset] = '\0';
        offset++;
    }
    *args = *args + offset;
    return (arg_two);
}

char *mod_parcer (char **args)
{
    int sep_offset = get_sep_offset(*args, sep_opps);
    int count = 0;
    char *tmp = NULL;

    if (sep_offset == -1)
        return;
    for (int i = 0; i < sep_offset; i++) {
        if ((*args)[i] == '\0' || (*args)[i] == ' ' || (*args)[i] == '\t')
            count++;
    }
    if (count + 1 == sep_offset) {
        parser(args, 0, sep_opps);
        tmp = alt_parce(args);
        return tmp;
    } else {
        return parser(args, 1, sep_opps);
    }
}