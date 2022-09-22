/*
** EPITECH PROJECT, 2022
** Utility fucntion
** File description:
** Returns an error msg to stderr
*/

#include "utilities.h"
#include <unistd.h>

void error (char *str)
{
    write(2, str, my_strlen(str));
}
