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

int verify(char **args, env_t *env)
{
    char *exceptions[] = {"../", "./", "/", ".", NULL};
    char *bin = args[0];
    char *dir_bin = get_bin_loc(env, bin);

    if (str_contains(args[0], exceptions, sep_sp_tab) < 4) {
        free(dir_bin);
        return 0;
    }
    if (bin == NULL || dir_bin == NULL)
        return 1;
    args[0] = dir_bin;
    free(bin);
    return 0;
}

static void record_result(env_t **env)
{
    int status = 0;

    wait(&status);
    if (WIFEXITED(status))
        status = WEXITSTATUS(status);
    add_to_env(env, "STATUS", int_to_str(status), 2);
}

static char **env_to_arr(env_t *env)
{
    env_t *tmp = env;
    char **arr = NULL;
    char *tmp_str = NULL;
    int i = 0;
    int j = 0;

    for (; tmp; tmp = tmp->next, j++);
    arr = malloc(sizeof(char *) * (j + 1));
    tmp = env;
    for (; tmp != NULL; tmp = tmp->next) {
        tmp_str = str_join(tmp->var, "=");
        arr[i] = str_join(tmp_str, tmp->value);
        i++;
        free(tmp_str);
    }
    arr[i] = NULL;
    return arr;
}

static void child_process(char **arr, env_t *env)
{
    char **envp = env_to_arr(env);

    if (execve(arr[0], arr, envp) == -1) {
        dup2(STDERR_FILENO, STDOUT_FILENO);
        delete_two_d_string(arr);
        delete_two_d_string(envp);
        exit(errno);
    }
}

void exec_bin(char *args, env_t **env)
{
    char **arr = split_str(args, sep_sp_tab);
    int fd_stdout = dup(STDOUT_FILENO);

    if (verify(arr, *env)) {
        dup2(STDERR_FILENO, STDOUT_FILENO);
        my_printf("bash: %s :command not found\n", arr[0]);
        delete_two_d_string(arr);
        add_to_env(env, "STATUS", "127", 1);
        dup2(fd_stdout, STDOUT_FILENO);
        return;
    }
    if (!fork())
        child_process(arr, *env);
    else
        record_result(env);
    delete_two_d_string(arr);
}
