/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** converts dex to hex
*/

#include "my_printf.h"
#include <stdlib.h>
#include <stdio.h>

static size_t get_digits(long long number)
{
    size_t count = 0;

    if (number == 0)
        return 1;
    if (number < 0) {
        ++count;
        number = number * (-1);
    }
    while (number > 0) {
        number /= 10;
        ++count;
    }
    return count;
}

static void rev_str(char *str)
{
    char tmp;
    int length = my_strlen(str);

    for (int i = 0; i < length / 2; ++i) {
        tmp = str[i];
        str[i] = str[(length - 1) - i];
        str[(length - 1) - i] = tmp;
    }
}

void null_buffer(char *buffer, size_t size)
{
    for (size_t i = 0; i <= size; i++) {
        buffer[i] = '\0';
    }
}

//converts dex to hex
char *pf_int_to_hex(long long number)
{
    size_t digits = get_digits(number);
    char *buffer = malloc(digits + 1);

    null_buffer(buffer, digits);
    for (size_t i = 0; number > 0; ++i) {
        if (i == 4095)
            break;
        if (number % 16 > 9)
            buffer[i] = (char) (number % 16) + 87;
        else
            buffer[i] = (char) (number % 16) + '0';
        number = number / 16;
    }
    buffer[digits] = '\0';
    rev_str(buffer);
    return buffer;
}
