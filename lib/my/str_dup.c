/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** functions to copy an str and dup str
*/

#include <stdlib.h>
#include "utilities.h"

void copy_str(char *dest, char const *src)
{
    int	i = 0;

    for ( ; src[i]; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
}

char *my_strdup(char const *src)
{
    char	*dest;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    copy_str(dest, src);
    return (dest);
}

void copyn_str(char *dest, char const *src, int n)
{
    int	i = 0;

    for ( ; i < n && src[i]; ++i)
        dest[i] = src[i];
    dest[i] = '\0';
}

void copy_nexact_str(char *dest, char const *src, int n)
{
    int	i = 0;

    for ( ; i < n && src[i]; ++i)
        dest[i] = src[i];
}

char *my_strndup(char const *src, int n)
{
    char	*dest;

    dest = malloc(sizeof(char) * (n + 1));
    copyn_str(dest, src, n);
    return (dest);
}
