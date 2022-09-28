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

int verify(char **args, env_t *env)
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

static void record_result(env_t **env)
{
    int status = 0;

    wait(&status);
    if (WIFEXITED(status))
        status = WEXITSTATUS(status);
    add_to_env(env, "STATUS", int_to_str(status), 1);
}

static char **env_to_arr(env)
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
    char *err = my_strdup(arr[0]);
    char **envp = env_to_arr(env);

    if (execve(arr[0], arr, envp) == -1) {
        dup2(STDERR_FILENO, STDOUT_FILENO);
        my_printf("bash: %s :command not found\n", err);
        delete_two_d_string(arr);
        delete_two_d_string(envp);
        free(err);
        exit(EXIT_ERR_EPI);
    }
}

void exec_bin(char *args, env_t **env)
{
    char **arr = split_str(args, sep_sp_tab);

    if (verify(arr, *env)) {
        error("Command not found\n");
        delete_two_d_string(arr);
        add_to_env(env, "STATUS", "127", 1);
        return;
    }
    if (!fork())
        child_process(arr, *env);
    else
        record_result(env);
    delete_two_d_string(arr);
}
