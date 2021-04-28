/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** pop_list.c
*/

#include "include/my.h"
#include "include/generator.h"

int pop_front(head_t *list)
{
    wall_t *tmp;

    if (list == NULL) {
        return (84);
    }
    if (list->first != NULL) {
        tmp = list->first->next;
        free(list->first);
        list->first = tmp;
    }
    return (0);
}

int pop_back(head_t *list)
{
    wall_t *tmp;

    if (list == NULL) {
        return (84);
    }
    if (list->first != NULL) {
        for (tmp = list->first; tmp->next->next != NULL; tmp = tmp->next);
        free(tmp->next);
        tmp->next = NULL;
    }
    return (0);
}