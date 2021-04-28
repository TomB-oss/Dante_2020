/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** print_list.c
*/

#include "include/my.h"
#include "../include/generator.h"

int print_list(head_t *list)
{
    wall_t *tmp;

    if (list == NULL) {
        return (84);
    }
    for (tmp = list->first; tmp != NULL; tmp = tmp->next) {
        if (tmp->next == NULL) {
            my_printf("[%d; %d] ", tmp->x, tmp->y);
        } else {
            my_printf("[%d; %d] -> ", tmp->x, tmp->y);
        }
    }
    my_printf("-> NULL\n");
    return (0);
}