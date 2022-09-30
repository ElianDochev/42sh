/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** Joins two strings into one
*/

#include "utilities.h"

char *str_join(char const *str_one, char const *str_two)
{
    int length_str_one = str_one != NULL ? my_strlen(str_one) : 0;
    int length_str_two = str_two != NULL ? my_strlen(str_two) : 0;
    char *new_str = str_one != NULL && str_two != NULL ?
    malloc(length_str_one + length_str_two + 1) : NULL;

    if (new_str == NULL)
        return NULL;
    for (int i = 0; i < length_str_one; i++)
        new_str[i] = str_one[i];
    for (int i = 0; i < length_str_two; i++)
        new_str[length_str_one + i] = str_two[i];
    new_str[length_str_one + length_str_two] = '\0';
    return new_str;
}
