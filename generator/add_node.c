/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** add_node.c
*/

#include "include/my.h"
#include "include/generator.h"

int add_front(head_t *l_a, int x, int y)
{
    wall_t *node = malloc(sizeof(*node));

    if (l_a == NULL || node == NULL) {
        return (84);
    }
    node->x = x;
    node->y = y;
    node->next = l_a->first;
    l_a->first = node;
    return (0);
}

int add_back(head_t *l_a, int x, int y)
{
    wall_t *node = malloc(sizeof(*node));
    wall_t *tmp;

    if (l_a == NULL || node == NULL) {
        return (84);
    }
    node->x = x;
    node->y = y;
    node->next = NULL;
    if (l_a->first == NULL) {
        l_a->first = node;
    } else {
        for (tmp = l_a->first; tmp->next != NULL; tmp = tmp->next);
        tmp->next = node;
    }
    return (0);
}