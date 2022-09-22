/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** converts a str into a string
*/

#include "utilities.h"

int str_to_int(const char *str)
{
    int res = 0;

    if (*str == '-')
        return res;
    for (int i = 0; str[i]; ++i)
        res = (res * 10) + (str[i] - '0');
    return res;
}
