/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** frees a 2d string array
*/

#include "utilities.h"
#include <stdlib.h>

void delete_two_d_string(char **w_arr)
{
    for (int i = 0; w_arr[i]; ++i)
        free(w_arr[i]);
    free(w_arr);
}
