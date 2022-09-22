/*
** EPITECH PROJECT, 2022
** minishell 2
** File description:
** parces the input according to the opps
*/

#include "main.h"

static int get_offset(char *arg, int (*sep)(char))
{
    int i = 0;

    for (; arg[i]; i++) {
        if (!sep(arg[i]))
            return i;
    }
    return i;
}

static char *do_for_first_arg(char **args, int (*sep)(char))
{
    int offset = get_offset(*args, sep);
    char *arg = *args;

    *args += offset;
    offset = 0;
    for (int i = 0; (*args)[i]; ++i) {
        if (sep((*args)[i])) {
            break;
        }
        ++offset;
        (*args)[i] = '\0';
    }
    *args += offset;
    return arg;
}

static void get_to_it(int len_arg_one, int len_arg_two, int opp_len,
char **args)
{
    char temp_arg_one[len_arg_one];
    char temp_arg_two[len_arg_two];
    int total_len = len_arg_one + len_arg_two + opp_len;

    for (int i = 0; i < len_arg_one; i++)
        temp_arg_one[i] = args[0][i];
    for (int i = 0; i < len_arg_two; i++)
        temp_arg_two[i] = args[0][len_arg_one + opp_len + i];
    copy_nexact_str(args[0], temp_arg_two, len_arg_two);
    for (int i = 0; i < opp_len; i++)
        args[0][len_arg_two + i] = '\0';
    copy_nexact_str(*args + len_arg_two + opp_len, temp_arg_one, len_arg_one);
}

static char *do_for_second_arg(char **args, int (*sep)(char))
{
    int len_arg_one = get_offset(*args, sep);
    int len_arg_two = 0;
    int opp_len = 0;
    char *tmp = *args;

    for (int i = len_arg_one; (*args)[i]; i++) {
        if (sep((*args)[i]))
            break;
        ++opp_len;
    }
    len_arg_two = get_offset((*args) + len_arg_one + opp_len, sep);
    get_to_it(len_arg_one, len_arg_two, opp_len, args);
    *args += len_arg_two + opp_len;
    return tmp;
}

char *parser(char **args, int is_second, int (*sep)(char))
{
    char *tmp;

    if (is_second) {
        tmp = do_for_second_arg(args, sep);
    } else {
        tmp = do_for_first_arg(args, sep);
    }
    return tmp;
}
