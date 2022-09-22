/*
** EPITECH PROJECT, 2022
** Lib func
** File description:
** Converts int into char *ptr
*/

#include <stdlib.h>
#include "my_printf.h"

static int get_number_digits(int *n, int *scr, pf_bool *m)
{
    int count = 0;

    if (*scr < 0) {
        (*n) = (*n) * (-1);
        (*scr) = (*scr) * (-1);
        *m = pf_true;
    }
    while (*n != 0) {
        *n = *n / 10;
        ++count;
    }
    return count;
}

static char *check_minus_zero(char *dest, int i, pf_bool minus, int num)
{
    if (num == 0) {
        free(dest);
        dest = malloc(2);
        dest[0] = '0';
        dest[1] = '\0';
        return dest;
    }
    dest[i - 1 + minus] = '\0';
    if (minus == pf_true)
        dest[0] = '-';
    return dest;
}

//converts an int to string (signed)
char *int_to_str(int scr)
{
    int n = scr;
    char tmp;
    char *dest;
    int i = 1;
    pf_bool minus = pf_false;
    int count = get_number_digits(&n, &scr, &minus);

    dest = malloc(count + 1 + minus);
    for (; i <= count; ++i) {
        n = scr;
        n = n / my_compute_power_rec(10, count - i);
        n = n % 10;
        tmp = n + 48;
        dest[i - 1 + minus] = tmp;
    }
    dest = check_minus_zero(dest, i, minus, scr);
    return dest;
}
