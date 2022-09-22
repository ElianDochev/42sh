/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** manages the input
*/

#include "main.h"
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int read_input(char *args)
{
    size_t bytes_read;
    size_t length = 1024;

    bytes_read = getline(&args, &length, stdin);
    if (bytes_read == 0)
        return 1;
    if (bytes_read == -1) {
        my_printf("\n");
        exit(84);
    }
    args[bytes_read - 1] = '\0';
    return 0;
}

int is_there_an_opp(char *args)
{
    int index;

    index = str_contains(args, opps, sep_opps);
    return index != get_len_two_d(opps) ? index : -1;
}

int get_command(char *args)
{
    char *commands[] =
    {"exit", "cd", "pwd", "setenv", "unsetenv", "env", NULL};
    int index = str_contains(args, commands, sep_sp_tab);

    return index;
}

void control_flow(char *args, char ***env, int *running)
{
    int index;

    if ((index = is_there_an_opp(args)) == -1) {
            index = get_command(args);
            index == 0 ? *running = 0 : fnc_arr[index - 1](args, env);
    } else
        index <= 3 ? right_assos(args, running, env, index) :
        left_assos(args, running, env, index);
}

void input_manager(char **env)
{
    int running = 1;
    int index;
    char args[KB];

    display_first_line(env);
    while (running)
    {
        if (read_input(args))
            continue;
        control_flow(args, &env, &running);
        if (running)
            display_first_line(env);
    }
}
