/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** prints things with flags
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

void clear_buffer(int *index, char *buff)
{
    *index = 0;
    for (int i = 0; i < 4095; ++i) {
        buff[i] = '\0';
    }
}

int gets_funcs_index(char *args)
{
    char funcs[] = "scdi%ubBxXoOpS";

    for (int i = 0; funcs[i] != '\0'; ++i) {
        if (funcs[i] == *(args + 1))
            return i;
    }
    return (14);
}

void dump_buffer(int *index, char *buff)
{
    write(1, buff, my_strlen(buff));
    clear_buffer(index, buff);
}

void mypr_calculate(char *args, mypt_buffer_t *buff, va_list *ap,
void(*func_array[15])(char *, va_list *))
{
    while (*args) {
        if (*args == '%' && *(args + 1) != '\0') {
            dump_buffer(&(buff->index), (buff->buf));
            func_array[(gets_funcs_index(args))](args, ap);
            args = args + 2;
            continue;
        }
        if (buff->index == 4094)
            dump_buffer(&(buff->index), (buff->buf));
        (buff->buf)[buff->index] = *args;
        ++(buff->index);
        ++args;
    }
}

void my_printf(char *args, ...)
{
    va_list ap;
    mypt_buffer_t *buff = malloc(sizeof(mypt_buffer_t));
    void (*func_array[])(char *, va_list *) = {&pf_flag_s, &pf_flag_c,
    &pf_flag_d, &pf_flag_i, &pf_flag_percent, &pf_flag_u, &pf_flag_b,
    &pf_flag_capital_b, &pf_flag_x, &pf_flag_capital_x, &pf_flag_o,
    &pf_flag_capital_o, &pf_flag_p, &pf_flag_capital_s, &pf_error};

    clear_buffer(&(buff->index), buff->buf);
    va_start(ap, args);
    mypr_calculate(args, buff, &ap, func_array);
    dump_buffer(&(buff->index), (buff->buf));
    free(buff);
    va_end(ap);
}
