/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** LEFT assoianted opps
*/

#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

static void input_redirect(char *args, char *arg_two,
int *running, env_t **env)
{
    int fd_status;
    int fd_stdin = dup(0);

    my_printf("taken %s, rest %s\n", arg_two, args);
    if ((fd_status = open(arg_two, O_RDONLY)) == -1) {
        add_to_env(env, STATUS, ERR_STATUS, 1);
        perror("bash: open");
        return;
    }
    dup2(fd_status, STDIN_FILENO);
    close(fd_status);
    control_flow(args, env, running);
    dup2(fd_stdin, STDIN_FILENO);
    close(fd_stdin);
}

static void second_part(char *args, int *fd_pipe,
int *running, env_t **env)
{
    int opp;
    int saved_fd = dup(STDIN_FILENO);

    close(fd_pipe[1]);
    dup2(fd_pipe[0], STDIN_FILENO);
    close(fd_pipe[0]);
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

static void here_doc_redirect(char *args, char *arg_two,
int *running, env_t **env)
{
    int fd_pipe[2];
    int status;

    if (pipe(fd_pipe) == -1) {
        perror("bash: pipe");
        add_to_env(env, STATUS, ERR_STATUS, 1);
        return;
    }
    if (!fork()) {
        child_pros(fd_pipe, arg_two);
    } else {
        wait(&status);
        if ((status = WEXITSTATUS(status)) == 137) {
            empty_pipe(fd_pipe);
            add_to_env(env, STATUS, ERR_STATUS, 1);
            return;
        }
        second_part(args, fd_pipe, running, env);
    }
}

void left_assos(char *args, int *running, env_t **env, int opp)
{
    char *arg_two = mod_parcer(&args);

    remove_sep(&arg_two, sep_sp_tab, 0);
    remove_sep(&args, sep_sp_tab, 0);
    if (opp == INX_LEFT_ASSOS + 1)
        here_doc_redirect(args, arg_two, running, env);
    else
        input_redirect(args, arg_two, running, env);
}
