/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** the extra stuff for the exec_bin function
*/

#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>


char *get_bin_loc(env_t *env , char *bin)
{
    char *tmp = malloc(sizeof(char) * 512);
    char **paths = NULL;

    null_buffer(tmp, 511);
    bin = str_join("/", bin);
    copy_str(tmp, find_var("PATH", env)->value);
    if ((paths = split_str_single(tmp, sep_colon)) == NULL)
        return NULL;
    free(tmp);
    for (int i = 0; paths[i]; i++) {
        tmp = str_join(paths[i], bin);
        if (access(tmp, X_OK) == 0)
            break;
        free(tmp);
        tmp = NULL;
    }
    delete_two_d_string(paths);
    free(bin);
    return tmp;
}
