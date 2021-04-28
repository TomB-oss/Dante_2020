/*
** EPITECH PROJECT, 2020
** dante_bis
** File description:
** check_surrounding.c
*/

#include "../include/generator.h"
#include "../include/my.h"

int surrounding_cell(gen_t *gen, int x, int y)
{
    int s_cells = 0;

    if (gen->map[y - 1][x] == '*') {
        s_cells += 1;
    }
    if (gen->map[y + 1][x] == '*') {
        s_cells += 1;
    }
    if (gen->map[y][x - 1] == '*') {
        s_cells += 1;
    }
    if (gen->map[y ][x + 1] == '*') {
        s_cells += 1;
    }
    return (s_cells);
}

int surrounding_cell_up(gen_t *gen, int x, int y)
{
    int s_cells = 0;

    if (gen->map[y + 1][x] == '*') {
        s_cells += 1;
    }
    if (gen->map[y][x + 1] == '*') {
        s_cells += 1;
    }
    return (s_cells);
}

int surrounding_cell_down(gen_t *gen, int x, int y)
{
    int s_cells = 0;

    if (gen->map[y - 1][x] == '*') {
        s_cells += 1;
    }
    if (gen->map[y][x - 1] == '*') {
        s_cells += 1;
    }
    return (s_cells);
}
