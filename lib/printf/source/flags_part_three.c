/*
** EPITECH PROJECT, 2022
** flags for my_printf
** File description:
** Part three - x, X, o, O
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

//flag %x
void pf_flag_x(char *args, va_list *ap)
{
    int number;
    char *result = NULL;

    number = va_arg(*ap, int);
    if (number < 0) {
        number = number * (-1);
        write(1, "-", 1);
    }
    result = pf_int_to_hex(number);
    write (1, result, my_strlen(result));
}

//flag %X
void pf_flag_capital_x(char *args, va_list *ap)
{
    int number;
    char *result = NULL;

    number = va_arg(*ap, int);
    if (number < 0) {
        number = number * (-1);
        write(1, "-", 1);
    }
    result = pf_int_to_hex(number);
    result = str_upcase(result);
    write (1, result, my_strlen(result));
}

//flag %o
void pf_flag_o(char *args, va_list *ap)
{
    char buffer[4096];
    int number;

    number = va_arg(*ap, int);
    if (number < 0) {
        number = number * (-1);
        write(1, "-", 1);
    }
    pf_init_b(buffer, 4096);
    for (int i = 0; number > 0; ++i) {
        if (i == 4095)
            break;
        buffer[i] = (number % 8) + '0';
        number = number / 8;
    }
    rev_buff(buffer, 4096);
    write (1, buffer, my_strlen(buffer));
}

//flag %O
void pf_flag_capital_o(char *args, va_list *ap)
{
    pf_flag_o(args, ap);
}
