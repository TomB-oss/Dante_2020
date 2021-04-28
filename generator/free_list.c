/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** free_list.c
*/

#include "include/my.h"
#include "include/generator.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}

int free_list(head_t *list)
{
    wall_t *tmp;

    if (list == NULL) {
        return (84);
    }
    if (list->first != NULL) {
        for (tmp = list->first; tmp != NULL; tmp = list->first) {
            tmp = tmp->next;
            free(list->first);
            list->first = tmp;
        }
    }
    free(list);
    return (0);
}