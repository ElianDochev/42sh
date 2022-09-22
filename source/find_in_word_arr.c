/*
** EPITECH PROJECT, 2022
** Minishell2
** File description:
** finds if the string is in a word_array
** and then gives the rest until it reaches the end returns NULL on falier
*/

#include "main.h"

static void stage_two(char *scr, int length, char *dest)
{
    int lenght_scr = my_strlen(scr);

    for (int i = 0; i + length <= lenght_scr; ++i)
        dest[i] = scr[i + length];
}

int str_in_word_arr(char *dest, char **word_arr, char *sub_arr)
{
    int length_sub = my_strlen(sub_arr);

    for (int i = 0; word_arr[i]; ++i) {
        if (str_ncmp(word_arr[i], sub_arr, length_sub) == 0) {
            stage_two(word_arr[i], length_sub, dest);
            return 0;
        }
    }
    return 1;
}