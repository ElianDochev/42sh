/*
** EPITECH PROJECT, 2022
** Utility functions
** File description:
** Removes the separators from a string from the both sides takes a callback
*/

#include "utilities.h"

static void null_buffer_fs(char *buffer, size_t size)
{
    for (size_t i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}

static void do_for_malloced(char **str, int offset, int len, int (*sep)(char))
{
    int back_offest = 0;
    char *tmp = NULL;

    for (int i = len - 1; i >= 0; i--) {
        if (sep((*str)[i]))
            back_offest++;
        else
            break;
    }
    tmp = malloc(sizeof(char) * (len - offset - back_offest + 1));
    null_buffer_fs(tmp, len - offset - back_offest + 1);
    for (int i = offset; i < len - back_offest; i++)
        tmp[i - offset] = (*str)[i];
    free(*str);
    *str = tmp;
}

void remove_sep(char **str, int (*sep)(char), int is_malloced)
{
    int offest = 0;
    int length = my_strlen(*str);

    for (int i = 0; (*str)[i]; i++) {
        if (!sep((*str)[i]))
            break;
        offest++;
    }
    if (is_malloced == 1)
        return do_for_malloced(str, offest, length, sep);
    *str += offest;
    length = my_strlen(*str);
    for (int i = length - 1; i >= 0; i--) {
        if (!sep((*str)[i]))
            break;
        length--;
    }
    (*str)[length] = '\0';
}
