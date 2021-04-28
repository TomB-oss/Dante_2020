/*
** EPITECH PROJECT, 2020
** dante_bis
** File description:
** check_around_cell.c
*/

#include "../include/generator.h"
#include "../include/my.h"

void check_up(gen_t *gen, int x, int y)
{
    int s_cell = 0;

    if (gen->map[y - 1][x] == 'u' && gen->map[y + 1][x] == '*') {
        s_cell = surrounding_cell(gen, x, y);
        if (s_cell < 2) {
            gen->map[y][x] = '*';
            upper_cell(gen, x, y);
            left_cell(gen, x, y);
            right_cell(gen, x, y);
        }
        pop_wall(gen, x, y);
    }
}

void check_down(gen_t *gen, int x, int y)
{
    int s_cell = 0;

    if (gen->map[y + 1][x] == 'u' && gen->map[y - 1][x] == '*') {
        s_cell = surrounding_cell(gen, x, y);
        if (s_cell < 2) {
            gen->map[y][x] = '*';
            bottom_cell(gen, x, y);
            left_cell(gen, x, y);
            right_cell(gen, x, y);
        }
        pop_wall(gen, x, y);
    }
}

void check_left(gen_t *gen, int x, int y)
{
    int s_cell = 0;

    if (gen->map[y][x - 1] == 'u' && gen->map[y][x + 1] == '*') {
        s_cell = surrounding_cell(gen, x, y);
        if (s_cell < 2) {
            gen->map[y][x] = '*';
            upper_cell(gen, x, y);
            bottom_cell(gen, x, y);
            left_cell(gen, x, y);
        }
        pop_wall(gen, x, y);
    }
}

void check_right(gen_t *gen, int x, int y)
{
    int s_cell = 0;

    if (gen->map[y][x + 1] == 'u' && gen->map[y][x - 1] == '*') {
        s_cell = surrounding_cell(gen, x, y);
        if (s_cell < 2) {
            gen->map[y][x] = '*';
            right_cell(gen, x, y);
            bottom_cell(gen, x, y);
            upper_cell(gen, x, y);
        }
        pop_wall(gen, x, y);
    }
}