/*
** EPITECH PROJECT, 2022
** minishell2
** File description:
** all the sep functions used as a callback
*/

#include "main.h"

int sep_sp_tab(char ch)
{
    if (ch == ' ' || ch == '\t')
        return 1;
    else
        return 0;
}

int sep_spacedash(char ch)
{
    if (ch == ' ' || ch == '/')
        return 1;
    else
        return 0;
}

int sep_alpha(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        return 0;
    if (ch >= 'A' && ch <= 'Z')
        return 0;
    return 1;
}

int sep_colon(char ch)
{
    if (ch == ':')
        return 1;
    return 0;
}

int sep_opps(char ch)
{
    if (ch == '<' || ch == '>')
        return 0;
    if (ch == '|' || ch == ';')
        return 0;
    return 1;
}
