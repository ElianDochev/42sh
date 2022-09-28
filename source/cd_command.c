/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** the cd command
*/

#include "main.h"
#include <unistd.h>
#include <stdio.h>

int check_access(char *path)
{
    if (access(path, X_OK) == -1) {
        perror("access");
        return 1;
    }
    else
        return 0;
}

//functions like pwd
void my_pwd(char *args, env_t **env)
{
    char cwd[KB];

    getcwd(cwd, sizeof(cwd));
    my_printf("%s\n", cwd);
}

static int case_one(char *old)
{
    char tmp[512];

    if (*old == '\0') {
        error("bash: cd: OLDPWD not set\n");
        return 1;
    }
    copy_str(tmp, old);
    getcwd(old, 512);
    chdir(tmp);
    my_pwd(NULL, NULL);
    return 0;
}

static void cd_cont(char **args, env_t *env, char *old)
{
    char *special[] = {"~", "-", NULL};
    int check = str_contains(args[1], special, sep_sp_tab);
    char *tmp;

    switch (check) {
    case 2:
        getcwd(old, 512);
        if (chdir(args[1]) == -1)
            perror(STD_ERR_MSG);
        break;
    case 1:
        if (case_one(old))
            return;
        break;
    case 0:
        getcwd(old, 512);
        tmp = find_var("HOME", env);
        check_access(tmp) == 0 ? chdir(tmp) : 0;
        break;
    }
}

void my_cd(char *args, env_t **env)
{
    char **arg = split_str(args, sep_sp_tab);
    static char old[512];
    char *tmp= NULL;

    if (arg[2] != NULL) {
        error("bash: cd: too many arguments");
        return;
    }
    if (arg[1] == NULL) {
        getcwd(old, 512);
        tmp = find_var("HOME", *env);
        check_access(tmp) == 0 ? chdir(tmp) : 0;
        return;
    }
    cd_cont(arg, *env, old);
    delete_two_d_string(arg);
}
