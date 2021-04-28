/*
** EPITECH PROJECT, 2020
** dante_bis
** File description:
** get_info.c
*/

#include "../include/generator.h"
#include "../include/my.h"

int get_y_from_list(head_t *list, int index)
{
    wall_t *tmp = list->first;
    int y = 0;

    for (int i = 0; i < index; i++, tmp = tmp->next);
    y = tmp->y;
    return (y);
}

int get_x_from_list(head_t *list, int index)
{
    wall_t *tmp = list->first;
    int x = 0;

    for (int i = 0; i < index; i++, tmp = tmp->next);
    x = tmp->x;
    return (x);
}

int get_wall(gen_t *gen)
{
    int count = 0;

    for (int y = 0; gen->map[y] != NULL; y++) {
        for (int x = 0; gen->map[y][x] != '\0'; x++) {
            if (gen->map[y][x] == 'X') {
                count += 1;
            }
        }
    }
    return (count);
}
