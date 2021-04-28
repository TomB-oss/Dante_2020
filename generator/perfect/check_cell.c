/*
** EPITECH PROJECT, 2020
** dante_bis
** File description:
** check_cell.c
*/

#include "../include/generator.h"
#include "../include/my.h"

void upper_cell(gen_t *gen, int x, int y)
{
    if (y != 0) {
        if (gen->map[y - 1][x] != '*') {
            gen->map[y - 1][x] = 'X';
        }
        if (is_in_walls(gen, x, y - 1) == 0) {
            add_back(gen->walls, x, y - 1);
        }
    }
}

void bottom_cell(gen_t *gen, int x, int y)
{
    if (y != gen->y_max - 1) {
        if (gen->map[y + 1][x] != '*') {
            gen->map[y + 1][x] = 'X';
        }
        if (is_in_walls(gen, x, y + 1) == 0) {
            add_back(gen->walls, x, y + 1);
        }
    }
}

void left_cell(gen_t *gen, int x, int y)
{
    if (x != 0) {
        if (gen->map[y][x - 1] != '*') {
            gen->map[y][x - 1] = 'X';
        }
        if (is_in_walls(gen, x - 1, y) == 0) {
            add_back(gen->walls, x - 1, y);
        }
    }
}

void right_cell(gen_t *gen, int x, int y)
{
    if (x != gen->x_max - 1) {
        if (gen->map[y][x + 1] != '*') {
            gen->map[y][x + 1] = 'X';
        }
        if (is_in_walls(gen, x + 1, y) == 0) {
            add_back(gen->walls, x + 1, y);
        }
    }
}
