/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** Displays error
*/

#include "my_printf.h"
#include <unistd.h>

void pf_error(char *args, va_list *ap)
{
    write(2, "invalid flag or not implemented", 31);
}
