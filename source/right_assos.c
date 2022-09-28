/*
** EPITECH PROJECT, 2022
** Minishell2
** File description:
** right assos opps
*/

#define _GNU_SOURCE
#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

void do_another_opp(char *args, int *running, env_t **env)
{
    char *arg = parser(&args, 0, sep_opps);

    control_flow(arg, env, running);
    control_flow(args, env, running);
}

void redirect_to_file(char *args, int *running, env_t **env, int overwrite)
{
    int fd_status;
    int fd_stdout = dup(STDOUT_FILENO);
    char *file = parser(&args, 1, sep_opps);

    remove_sep(&file, sep_sp_tab, 0);
    if ((fd_status = open(file, O_CREAT | O_RDWR |
    (overwrite == 1 ? O_TRUNC : O_APPEND), 0644)) == -1)
        perror("bash: open");
    dup2(fd_status, STDOUT_FILENO);
    close(fd_status);
    control_flow(args, env, running);
    dup2(fd_stdout, STDOUT_FILENO);
    close(fd_stdout);
}

void right_assos(char *args, int *running, env_t **env, int opp)
{
    if (opp == 0)
        return do_another_opp(args, running, env);
    if (opp == 1)
        return redirect_to_file(args, running, env, 0);
    if (opp == 2)
        return redirect_to_file(args, running, env, 1);
    if (opp == 3)
        return pipe_command(args, running, env);
}
