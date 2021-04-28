/*
** EPITECH PROJECT, 2020
** ant_man
** File description:
** main.c
*/

#include "include/generator.h"
#include "include/my.h"

static void column(gen_t *gen, int i)
{
    for (int j = 0; gen->map[i][j]; j++) {
        gen->map[i][j] = '*';
    }
}

static void line(gen_t *gen, int i)
{
    for (int j = 0; gen->map[i][j]; j++) {
        if (j % 2 == 0)
            gen->map[i][j] = '*';
    }
}

static int trans_map(gen_t *gen)
{
    int path = rand() % 2;

    if (path == 0) {
        for (int i = 0; gen->map[i]; i++) {
            if (i % 2 == 0)
                column(gen, i);
        }
    } else {
        for (int i = 0; gen->map[i]; i++) {
            line(gen, i);
        }
    }
    return (path);
}

void perfect(gen_t *gen)
{
    int path = 0;
    int final = rand() % gen->yend;
    int final_two = rand() % gen->xend;
    gen->map[gen->yend][gen->xend] = '*';

    path = trans_map(gen);
    if (path == 0) {
        for (int i = 0; gen->map[i]; i++) {
            gen->map[i][final] = '*';
        }
    } else {
        for (int i = 0; gen->map[final_two][i]; i++) {
            gen->map[final_two][i] = '*';
        }
    }
}