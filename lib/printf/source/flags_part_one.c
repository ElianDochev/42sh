/*
** EPITECH PROJECT, 2022
** flags for my_printf
** File description:
** Part one - i, d, s, c, %%
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

//flag %s
void pf_flag_s(char *args, va_list *ap)
{
    char *tmp = NULL;

    tmp = va_arg(*ap, char *);
    write(1, tmp, my_strlen(tmp));
}

//flag %c
void pf_flag_c(char *args, va_list *ap)
{
    char *tmp = NULL;

    tmp = pf_convert_to_str((char) va_arg(*ap, int));
    write(1, tmp, my_strlen(tmp));
    free(tmp);
}

//flag %d
void pf_flag_d(char *args, va_list *ap)
{
    char *tmp = NULL;

    tmp = int_to_str(va_arg(*ap, int));
    write(1, tmp, my_strlen(tmp));
    free(tmp);
}

//flag %i
void pf_flag_i(char *args, va_list *ap)
{
    pf_flag_d(args, ap);
}

//flag %%
void pf_flag_percent(char *args, va_list *ap)
{
    write(1, "%", 1);
}
