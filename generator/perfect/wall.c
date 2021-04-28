/*
** EPITECH PROJECT, 2020
** dante_bis
** File description:
** wall.c
*/

#include "../include/generator.h"
#include "../include/my.h"

int is_in_walls(gen_t *gen, int x, int y)
{
    wall_t *tmp = gen->walls->first;

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->x == x && tmp->y == y) {
            return (1);
        }
    }
    return (0);
}

int pop_last(gen_t *gen, int x, int y)
{
    wall_t *tmp2 = gen->walls->first;

    if (list_size(gen->walls) > 3) {
        for (; tmp2->next != NULL; tmp2 = tmp2->next);
        if (tmp2->x == x && tmp2->y == y) {
            pop_back(gen->walls);
            return (1);
        }
    }
    return (0);
}

void pop_wall(gen_t *gen, int x, int y)
{
    wall_t *tmp = gen->walls->first;
    wall_t *prev = NULL;

    if (pop_last(gen, x, y) == 1) {
        return;
    }
    if (tmp->x == x && tmp->y == y) {
        pop_front(gen->walls);
    } else {
        for (; tmp->next != NULL; tmp = tmp->next) {
            if (tmp->next->x == x && tmp->next->y == y) {
                tmp->next = tmp->next->next;
                break;
            }
        }
    }
}