/*
** EPITECH PROJECT, 2022
** flags for my_printf
** File description:
** Part two - u, b
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

//flag %u
void pf_flag_u(char *args, va_list *ap)
{
    char *tmp = NULL;

    tmp = int_to_str_unsigned(va_arg(*ap, unsigned int));
    write(1, tmp, my_strlen(tmp));
    free(tmp);
}

//flag %b
void pf_flag_b(char *args, va_list *ap)
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
        buffer[i] = (number % 2) + '0';
        number = number / 2;
    }
    rev_buff(buffer, 4096);
    write (1, buffer, my_strlen(buffer));
}

//flag %B
void pf_flag_capital_b(char *args, va_list *ap)
{
    pf_flag_b(args, ap);
}
