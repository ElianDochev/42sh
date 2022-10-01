/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** compares two strings
*/

#include "utilities.h"

int str_cmp(char const *str_one, char const *str_two)
{
    if (*str_one == '\0' && *str_two == '\0')
        return 0;
    return ((*str_one - *str_two) == 0) ? str_cmp(str_one + 1, str_two + 1) :
    (*str_one - *str_two);
}

int str_ncmp(char const *str_one, char const *str_two, int length)
{
    int res = 0;
    int count = 0;
    int len_s_one = my_strlen(str_one);
    int len_s_two = my_strlen(str_two);

    if ((len_s_one + len_s_two) == 0)
        return 0;
    if (len_s_one == 0)
        return -1;
    if (len_s_two == 0)
        return 1;
    if (length > MIN(len_s_one + 1, len_s_two + 1))
        length = MIN(len_s_one + 1, len_s_two + 1);
    while (res == 0 && count < length) {
        res = *str_one - *str_two;
        ++str_one;
        ++str_two;
        ++count;
    }
    return res;
}

int get_len_two_d(char **w_arr)
{
    int count = 0;

    while (*w_arr) {
        ++count;
        ++w_arr;
    }
    return count;
}

int str_contains_arg(char *scr, char **sub_arrays, int (*sup)(char))
{
    int len_sub_arrs = get_len_two_d(sub_arrays);
    int offset = 0;

    if (scr == NULL)
        return -1;
    for (int i = 0; scr[i]; ++i) {
        if ((!sup(scr[i])) != 0)
            break;
        ++offset;
    }
    scr = scr + offset;
    for (int i = 0; i < len_sub_arrs; ++i) {
        if (str_ncmp(scr, sub_arrays[i], my_strlen(sub_arrays[i])) == 0 &&
        (scr[my_strlen(sub_arrays[i])] == '\0' ||
        sup(scr[my_strlen(sub_arrays[i])])))
            return i;
    }
    return len_sub_arrs;
}

int str_contains(char *scr, char **sub_arrays, int (*sup)(char))
{
    int len_sub_arrs = get_len_two_d(sub_arrays);
    int offset = 0;

    if (scr == NULL)
        return -1;
    for (int i = 0; scr[i]; ++i) {
        if ((!sup(scr[i])) != 0)
            break;
        ++offset;
    }
    scr = scr + offset;
    for (int i = 0; i < len_sub_arrs; ++i) {
        if (str_ncmp(scr, sub_arrays[i], my_strlen(sub_arrays[i])) == 0)
            return i;
    }
    return len_sub_arrs;
}
