/*
** EPITECH PROJECT, 2022
** flags for my_printf
** File description:
** Part one - p, S
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

void get_oct(unsigned char ch, char *tmp)
{
    char swap;

    tmp[4] = '\\';
    tmp[0] = '\0';
    for (int i = 1; i < 4; ++i)
        tmp[i] = '0';
    for (int i = 1; ch > 0; ++i) {
        tmp[i] = (ch % 8) + '0';
        ch = ch / 8;
    }
    for (int i = 0; i < 5 / 2; ++i) {
        swap = tmp[i];
        tmp[i] = tmp[4 - i];
        tmp[4 - i] = swap;
    }
}

//flag %p
void pf_flag_p(char *args, va_list *ap)
{
    void *ptr;
    char *result = NULL;

    write(1, "0x", 2);
    ptr = va_arg(*ap, void *);
    result = pf_int_to_hex((long long) ptr);
    write(1, result, my_strlen(result));
    free(result);
}

//flag %S
void pf_flag_capital_s(char *args, va_list *ap)
{
    char *str = NULL;
    char tmp[5];

    str = va_arg(*ap, char *);
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] < 32 || str[i] > 127) {
            get_oct(str[i], tmp);
            write(1, tmp, 4);
            continue;
        }
        write(1, str + i, 1);
    }
}
