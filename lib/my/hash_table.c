/*
** EPITECH PROJECT, 2022
** Utility
** File description:
** Hash function and lookup
*/

#include "utilities.h"

// time complexitie Best O(1), Worst O(n) , averega O(logn) best likely
char **init_table_hash(size_t table_size)
{
    char **table = malloc(table_size * sizeof(char *));

    for (size_t i = 0; i < table_size; i++)
        table[i] = NULL;
    return table;
}

size_t hash_data(char *str, size_t table_size)
{
    size_t hash = 5381;
    int c;

    while (*str) {
        c = *str;
        hash = ((hash << 5) + hash) + c;
        ++str;
    }
    return (hash % table_size);
}

int incert_table_hash(char **table, char *str, size_t table_size)
{
    size_t index = hash_data(str, table_size);
    size_t try = 0;

    if (table == NULL || str == NULL)
        return -1;
    for (size_t i = 0; i < table_size; ++i) {
        try = (i + index) % table_size;
        if (table[try] == NULL) {
            table[try] = str;
            return 0;
        }
    }
    return -1;
}

char *lookup_table(char **table, char *str, size_t table_size)
{
    size_t index = hash_data(str, table_size);
    size_t try = 0;

    for (size_t i = 0; i < table_size; ++i) {
        try = (i + index) % table_size;
        if (table[try] != NULL && str_cmp(table[try], str) == 0)
            return table[try];
    }
    return NULL;
}

void hash_note_del(char **table, char *str, size_t table_size)
{

    size_t index = hash_data(str, table_size);
    size_t try = 0;

    for (size_t i = 0; i < table_size; ++i) {
        try = (i + index) % table_size;
        if (table[try] != NULL && str_cmp(table[try], str) == 0)
            table[try] = NULL;
    }
}
