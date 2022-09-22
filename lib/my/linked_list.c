/*
** EPITECH PROJECT, 2022
** Utilities
** File description:
** linked list
*/

#include "utilities.h"

static node_t *create_note(void *value)
{
    node_t *note = malloc(sizeof(node_t));

    note->next = NULL;
    note->value = value;
    return note;
}

node_t *list_incert(node_t *list, void *value)
{
    if (list == NULL)
        return create_note(value);
    else
        list->next = list_incert(list->next, value);
    return list;
}

//starts from 0
node_t *peek_index(node_t *list, int index)
{
    for (int i = 0; i < index && list->next != NULL; ++i)
        list = list->next;
    return list;
}

void destroy_list(node_t **list)
{
    node_t *tmp;

    while (*list == NULL) {
        tmp = *list;
        *list = (*list)->next;
        free(tmp);
    }
}
