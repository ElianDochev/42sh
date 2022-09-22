/*
** EPITECH PROJECT, 2022
** project name
** File description:
** main
*/

#include "main.h"
#include <signal.h>

int sig_handler(int sig)
{
    return 0;
}

static void malloc_env(char ***env)
{
    char **tmp = malloc(sizeof(char *) * (get_len_two_d(*env) + 2));

    for (int i = 0; (*env)[i] != NULL; ++i)
        tmp[i] = (*env)[i];
    *env = tmp;
}

void display_first_line(char **env)
{
    char buff[KB];
    int offset = 0;
    char *tmp = NULL;
    char user[KB];

    getcwd(buff, sizeof(buff));
    for (int i = my_strlen(buff); i > 0; --i) {
        if (buff[i] == '/')
            break;
        ++offset;
    }
    tmp = buff + (my_strlen(buff) - offset + 1);
    str_in_word_arr(user, env, "LOGNAME=");
    my_printf("[%s %s]$> ", user, tmp);
}

int main (int ac, char **av, char **env)
{
    if (ac == 2  && str_cmp(av[1], "-h") == 0) {
        print_help("./usage.txt");
        return 0;
    }
    if (ac > 1) {
        print_bad_args(ac, "mysh", 0);
        return EXIT_ERR_EPI;
    }
    signal(SIGINT, sig_handler);
    signal(SIGQUIT, sig_handler);
    malloc_env(&env);
    input_manager(env);
    return 0;
}
