/*
** EPITECH PROJECT, 2022
** Unility function
** File description:
** Write a function that makes every letter of every word in it in uppercase
*/

//converst letters to uppercase
char *str_upcase(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return str;
}
