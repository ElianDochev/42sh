/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** the cd command
*/

#include "main.h"
#include <unistd.h>
#include <stdio.h>

#include "main.h"
#include <unistd.h>
#include <stdio.h>

int check_access(char *path)
{
    if (access(path, X_OK) == -1) {
        perror("access");
        return 1;
    } else
        return 0;
}

//functions like pwd
void my_pwd(char *args, env_t **env)
{
    char cwd[KB];

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        my_printf("%s\n", cwd);
        add_to_env(env, STATUS, SUCCESS_STATUS, 1);
    } else {
        perror("getcwd() error");
        add_to_env(env, STATUS, ERR_STATUS, 1);
    }
}

static int case_one(char *old, env_t **env)
{
    char tmp[512];

    if (*old == '\0') {
        error("bash: cd: OLDPWD not set\n");
        add_to_env(env, STATUS, ERR_STATUS, 1);
        return 1;
    }
    copy_str(tmp, old);
    if (getcwd(old, 512) == NULL) {
        error("bash: cd: OLDPWD not set\n");
        add_to_env(env, STATUS, ERR_STATUS, 1);
        return 1;
    }
    if (chdir(tmp) == -1) {
        error("bash: cd: OLDPWD not set\n");
        add_to_env(env, STATUS, ERR_STATUS, 1);
        return 1;
    }
    my_pwd(NULL, env);
    return 0;
}

static void cd_cont(char **args, env_t **env, char *old)
{
    char *special[] = {"~", "-", NULL};
    int check = str_contains(args[1], special, sep_sp_tab);
    char *tmp;

    switch (check) {
    case 2:
        if (getcwd(old, 512) == NULL || chdir(args[1]) == -1)
            perror(STD_ERR_MSG);
        break;
    case 1:
        if (case_one(old, env))
            return;
        break;
    case 0:
        getcwd(old, 512);
        tmp = find_var("HOME", *env) ? find_var("HOME", *env)->value : NULL;
        check_access(tmp) == 0 ? chdir(tmp) : add_to_env(env, STATUS, "1", 1);
        return;
    }
    add_to_env(env, STATUS, SUCCESS_STATUS, 1);
}

void my_cd(char *args, env_t **env)
{
    char **arg = split_str(args, sep_sp_tab);
    static char old[512];
    char *tmp = NULL;

    if (arg[1] != NULL && arg[2] != NULL) {
        error("bash: cd: too many arguments\n");
        return add_to_env(env, STATUS, ERR_STATUS, 1);
    }
    if (arg[1] == NULL) {
        if (getcwd(old, 512) == NULL) {
            perror("getcwd() error");
            return add_to_env(env, STATUS, ERR_STATUS, 1);
        }
        tmp = find_var("HOME", *env)->value;
        check_access(tmp) == 0 ? chdir(tmp), add_to_env(env, STATUS, "0", 1)
        : add_to_env(env, STATUS, ERR_STATUS, 1);
        return;
    }
    cd_cont(arg, env, old);
    delete_two_d_string(arg);
}
