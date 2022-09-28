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

static void child_process(char *args, int *fd_pipe, int *running, env_t **env)
{
    close(fd_pipe[0]);
    dup2(fd_pipe[1], 1);
    close(fd_pipe[1]);
    control_flow(args, env, running);
    exit(EXIT_SUCCESS);
}

void pipe_command(char *args, int *running, env_t **env)
{
    int fd_pipe[2];
    int fd_tmp;
    char *arg_one = parser(&args, 0, sep_opps);

    if (pipe(fd_pipe) == -1) {
        perror("pipe");
        return;
    }
    if (!fork()) {
        child_process(arg_one, fd_pipe, running, env);
    } else {
        close(fd_pipe[1]);
        fd_tmp = dup(STDIN_FILENO);
        dup2(fd_pipe[0], STDIN_FILENO);
        close(fd_pipe[0]);
        wait(NULL);
        control_flow(args, env, running);
        dup2(fd_tmp, 0);
        close(fd_tmp);
    }
}
