/*
** EPITECH PROJECT, 2022
** minishell 2
** File description:
** functions for pipe command
*/

#include "main.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

static void child_process(char *args, int *fd_pipe, int *running, env_t **env)
{
    close(fd_pipe[0]);
    dup2(fd_pipe[1], 1);
    close(fd_pipe[1]);
    control_flow(args, env, running);
    exit(str_to_int(find_var(STATUS, *env)->value));
}

static void parent_process(char *args, int *fd_pipe, int *running, env_t **env)
{
    int fd_tmp;
    int status;

    close(fd_pipe[1]);
    fd_tmp = dup(STDIN_FILENO);
    dup2(fd_pipe[0], STDIN_FILENO);
    close(fd_pipe[0]);
    wait(&status);
    if (WIFEXITED(status)) {
        status = WEXITSTATUS(status);
        if (status != 0)
            add_to_env(env, STATUS, int_to_str(status), 2);
        else
            control_flow(args, env, running);
        dup2(fd_tmp, 0);
        close(fd_tmp);
    }
}

void pipe_command(char *args, int *running, env_t **env)
{
    int fd_pipe[2];
    char *arg_one = parser(&args, 0, sep_opps);

    if (pipe(fd_pipe) == -1) {
        perror("pipe");
        return;
    }
    if (!fork()) {
        child_process(arg_one, fd_pipe, running, env);
    } else {
        parent_process(args, fd_pipe, running, env);
    }
}
