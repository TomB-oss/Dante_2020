/*
** EPITECH PROJECT, 2020
** dante_bis
** File description:
** final_trail.c
*/

#include "../include/generator.h"
#include "../include/my.h"

int check_first_point(gen_t *gen, int x, int y)
{
    if (x == 0 && y == 0) {
        gen->map[y][x] = '*';
        while (surrounding_cell_up(gen, x, y) < 1) {
            gen->map[y][x + 1] = '*';
            x += 1;
        }
    }
    return (0);
}

int check_last_point(gen_t *gen, int x, int y)
{
    if (y == gen->y_max - 1 && x == gen->x_max - 1) {
        gen->map[gen->y_max - 1][gen->x_max - 1] = '*';
        while (surrounding_cell_down(gen, x, y) < 1) {
            gen->map[y][x - 1] = '*';
            x -= 1;
        }
    }
}

void main_trail(gen_t *gen)
{
    gen->map[gen->y_max - 1][gen->x_max - 1] = '*';

    for (int y = 0; y < gen->y_max; y++) {
        for (int x = 0; x < gen->x_max; x++) {
            check_first_point(gen, x, y);
            check_last_point(gen, x, y);
        }
    }
}