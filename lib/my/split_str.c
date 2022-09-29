/*
** EPITECH PROJECT, 2022
** rip
** File description:
** ma fonction
*/

#include "utilities.h"
#include <stdbool.h>
#include <stdlib.h>

static int countcharw(char *str, int i, int (*delim)(char))
{
    int count = 0;

    while (!delim(str[i]) && str[i] != '\0') {
        ++count;
        ++i;
    }
    return (count);
}

static char *copy_in_board(int *cpy2, char *str, int *i, int (*delim)(char))
{
    char *dest = NULL;

    *cpy2 = countcharw(str, *i, delim);
    dest = malloc(sizeof(char) * (*cpy2 + 1));
    dest[*cpy2] = '\0';
    *cpy2 = 0;
    return dest;
}

static char **copy(char **dest, char *str, int words, int (*delim)(char))
{
    int i = 0;
    int cpy1 = 0;
    int cpy2 = 0;

    while (cpy1 < words) {
        while (!delim(str[i]) == false)
            ++i;
        if (!delim(str[i]))
            dest[cpy1] = copy_in_board(&cpy2, str, &i, delim);
        while (!delim(str[i]) && str[i] != '\0') {
            dest[cpy1][cpy2] = str[i];
            ++i;
            ++cpy2;
        }
        if (!delim(str[i]) == false || str[i] == '\0')
            ++cpy1;
        while (!delim(str[i]) == false && str[i] != '\0')
            ++i;
    }
    return (dest);
}

static int countword(char *str, int (*delim)(char))
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (!delim(str[i])) {
            ++count;
            ++i;
        }
        while (!delim(str[i]) && str[i] != '\0')
            ++i;
        ++i;
    }
    return (count);
}

char **split_str(char *str, int (*delim)(char))
{
    int words = 0;
    char **dest = NULL;

    if (str == NULL)
        return NULL;
    words = countword(str, delim);
    dest = malloc (sizeof(char *) * (words + 1));
    dest[words] = NULL;
    dest = copy(dest, str, words, delim);
    return (dest);
}
