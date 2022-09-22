/*
** EPITECH PROJECT, 2022
** Lib func
** File description:
** Converts int into char *ptr
*/

#include <stdlib.h>
#include "my_printf.h"

//converts an int to string (unsigned)
char *int_to_str_unsigned(unsigned int scr)
{
    unsigned int n = scr;
    char tmp;
    char *dest;
    int count = 0;

    while (n > 0) {
        n /= 10;
        ++count;
    }
    dest = malloc(count + 1);
    for (int i = 1; i <= count; ++i) {
        n = scr;
        n = n / my_compute_power_rec(10, count - i);
        n = n % 10;
        tmp = n + 48;
        dest[i - 1] = tmp;
    }
    dest[count] = '\0';
    return dest;
}
