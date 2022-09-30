/*
** EPITECH PROJECT, 2022
** minishell 1
** File description:
** functions for pipes and signals
*/

#include "main.h"
#include <fcntl.h>
#include <unistd.h>

void signal_sigint(int sig)
{
    write(2, "\n", 1);
    exit(137);
}

void empty_pipe(int *pipefd)
{
    char tmp[16];

    close(pipefd[1]);
    while (read(pipefd[0], tmp, 16) > 0);
    close(pipefd[0]);
}