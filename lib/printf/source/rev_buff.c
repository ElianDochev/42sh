/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** reverses a string with know size
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_printf.h"

//set the values of the chars to '\0'
void pf_init_b(char *buff, int size)
{
    for (int i = 0; i < size; ++i) {
        buff[i] = '\0';
    }
}

//reverses a string with know size
void rev_buff(char *buff, int size)
{
    char tmp;
    size = my_strlen(buff);

    for (int i = 0; i < size / 2; ++i) {
        tmp = buff[i];
        buff[i] = buff[size - i - 1];
        buff[size - i - 1] = tmp;
    }
}
