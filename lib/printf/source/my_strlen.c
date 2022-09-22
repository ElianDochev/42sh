/*
** EPITECH PROJECT, 2022
** Utility function
** File description:
** Return len of str
*/

//selfexcpanatory
int my_strlen(char const *str)
{
    int len = 0;

    if (str == (void *)0)
        return 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        ++len;
    }
    return len;
}
