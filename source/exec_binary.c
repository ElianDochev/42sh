/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** exectutes programs
*/

#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

char *get_bin_loc(char **env , char *bin)
{
    char *tmp = malloc(sizeof(char) * 512);
    char **paths = NULL;

    null_buffer(tmp, 511);
    bin = str_join("/", bin);
    str_in_word_arr(tmp, env, "PATH=");
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

int verify(char **args, char **env)
{
    char *exceptions[] = {"../", "./", "/", ".", NULL};
    char *bin = args[0];
    char *dir_bin = get_bin_loc(env, bin);

    if (bin == NULL)
        return 1;
    if (str_contains(args[0], exceptions, sep_sp_tab) < 4) {
        free(dir_bin);
        return 0;
    }
    args[0] = dir_bin;
    free(bin);
    return 0;
}

void exec_bin(char *args, char ***env)
{
    char **arr = split_str(args, sep_sp_tab);
    char *err = my_strdup(arr[0]);

    if (verify(arr, *env)) {
        error("Command not found\n");
        delete_two_d_string(arr);
        return;
    }
    if (!fork()) {
        if (execve(arr[0], arr, *env) == -1) {
            dup2(STDERR_FILENO, STDOUT_FILENO);
            my_printf("bash: %s :command not found\n", err);
            delete_two_d_string(arr);
            free(err);
            exit(EXIT_ERR_EPI);
        }
    } else
        wait(NULL);
    delete_two_d_string(arr);
    free(err);
}
