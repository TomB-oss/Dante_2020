/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** list_size.c
*/

#include "include/my.h"
#include "../include/generator.h"
#include <assert.h>

int list_size(head_t *list)
{
    wall_t *tmp;
    int i = 0;

    if (list == NULL)
        return (84);
    for (tmp = list->first; tmp != NULL; tmp = tmp->next, i++);
    return (i);
}