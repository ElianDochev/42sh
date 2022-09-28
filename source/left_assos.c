/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** LEFT assoianted opps
*/

#define _GNU_SOURCE
#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

static void input_redirect(char *args, int *running, env_t **env, int opp)
{
    int fd_status;
    int fd_stdin = dup(0);
    char *file = parser(&args, 1, sep_opps);

    remove_sep(&file, sep_sp_tab, 0);
    if ((fd_status = open(file, O_RDONLY)) == -1) {
        add_to_env(env, "STATUS", "1", 1);
        perror("bash: open");
        return;
    }
    dup2(fd_status, STDIN_FILENO);
    close(fd_status);
    control_flow(args, env, running);
    dup2(fd_stdin, STDIN_FILENO);
    close(fd_stdin);
}

static void second_part(char *args, int fd_tmp, int *running, env_t **env)
{
    int opp;
    int saved_fd = dup(STDIN_FILENO);

    dup2(fd_tmp, STDIN_FILENO);
    close(fd_tmp);
    control_flow(args, env, running);
    dup2(saved_fd, STDIN_FILENO);
    close(saved_fd);
}

static void child_pros(int *fd_pipe, char *stop)
{
    char tmp[KB];

    dup2(fd_pipe[1], STDOUT_FILENO);
    close(fd_pipe[0]);
    close(fd_pipe[1]);
    remove_sep(&stop, sep_sp_tab, 0);
    write(STDERR_FILENO, ">", 1);
    while (1) {
        if (read_input(tmp) == 1)
            continue;
        if (str_cmp(tmp, stop) == 0)
            break;
        write(STDERR_FILENO, ">", 1);
        my_printf("%s\n", tmp);
        signal(SIGINT, signal_sigint);
    }
    exit(EXIT_SUCCESS);
}

static void here_doc_redirect(char *args, int *running, env_t **env, int opp)
{
    int fd_pipe[2];
    char *stop = parser(&args, 1, sep_opps);
    int status;

    pipe(fd_pipe);
    if (!fork()) {
        child_pros(fd_pipe, stop);
    } else {
        wait(&status);
        if ((status = WEXITSTATUS(status)) == 137) {
            empty_pipe(fd_pipe);
            return;
        }
        close(fd_pipe[1]);
        second_part(args, fd_pipe[0], running, env);
        close(fd_pipe[0]);
    }
}

void left_assos(char *args, int *running, env_t **env, int opp)
{
    if (opp == 5)
        input_redirect(args, running, env, opp);
    else
        here_doc_redirect(args, running, env, opp);
}
