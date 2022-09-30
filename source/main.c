/*
** EPITECH PROJECT, 2022
** project name
** File description:
** main
*/

#include "main.h"
#include <signal.h>
#include <string.h>

int sig_handler(int sig)
{
    return 0;
}

void display_first_line(env_t *env)
{
    char buff[KB];
    int offset = 0;
    char *tmp = NULL;
    char *user;

    if (getcwd(buff, sizeof(buff)) == NULL)
        return;
    for (int i = my_strlen(buff); i > 0; --i) {
        if (buff[i] == '/')
            break;
        ++offset;
    }
    tmp = buff + (my_strlen(buff) - offset + 1);
    user = find_var("USER", env) ? find_var("USER", env)->value : "user";
    my_printf("[%s %s]$> ", user, tmp);
}

static env_t *init_env(char **env_old)
{
    env_t *env = NULL;
    char *tmp = NULL;

    for (int i = 0; env_old[i] != NULL; ++i) {
        tmp = strtok(env_old[i], "=");
        add_to_env(&env, tmp, strtok(NULL, "="), 0);
    }
    add_to_env(&env, STATUS, SUCCESS_STATUS, 1);
    return env;
}

static void free_env(env_t *env)
{
    env_t *tmp = NULL;

    for (; env != NULL; env = tmp) {
        tmp = env->next;
        env->malloced & FREE_VAR ? free(env->var) : 0;
        env->malloced & FREE_VALUE ? free(env->value) : 0;
        free(env);
    }
}

int main (int ac, char **av, char **env_old)
{
    env_t *env = NULL;
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
    env = init_env(env_old);
    input_manager(&env);
    free_env(env);
    return 0;
}
