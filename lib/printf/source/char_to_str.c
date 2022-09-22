/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** Converts a char to full string
*/

#include "stdlib.h"

//mallocs a new string contaning the char + '\0'
char *pf_convert_to_str(char ch)
{
    char *str = malloc(2);

    str[0] = ch;
    str[1] = '\0';
    return str;
}
