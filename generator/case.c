/*
** EPITECH PROJECT, 2020
** ant_man
** File description:
** main.c
*/

#include "include/generator.h"
#include "include/my.h"

int next_left(gen_t *gen)
{
    if (gen->posx == 0)
        return (1);
    else if (gen->lastmovex == (gen->posx - 1) &&
    gen->lastmovey == (gen->posy)) {
        return (1);
    } else {
        gen->map[gen->posy][gen->posx - 1] = '*';
        gen->lastmovex = gen->posx;
        gen->posx -= 1;
    }
}

int next_right(gen_t *gen)
{
    if (gen->map[gen->posy][gen->posx + 1] == '\0')
        return (1);
    else if (gen->lastmovex == (gen->posx + 1) &&
    gen->lastmovey == (gen->posy)) {
        return (1);
    } else {
        gen->map[gen->posy][gen->posx + 1] = '*';
        gen->lastmovex = gen->posx;
        gen->posx += 1;
    }
}

int next_up(gen_t *gen)
{
    if (gen->posy == 0 || gen->lastmovey == (gen->posy - 1))
        return (1);
    else if (gen->lastmovey == (gen->posy - 1) &&
    gen->lastmovex == gen->posx) {
        return (1);
    } else {
        gen->map[gen->posy - 1][gen->posx] = '*';
        gen->lastmovey = gen->posy;
        gen->posy -= 1;
    }
}

int next_down(gen_t *gen)
{
    if (gen->map[gen->posy + 1] == NULL || gen->lastmovey == (gen->posy + 1))
        return (1);
    else if (gen->lastmovey == (gen->posy - 1) &&
    gen->lastmovex == gen->posx) {
        return (1);
    } else {
        gen->map[gen->posy + 1][gen->posx] = '*';
        gen->lastmovey = gen->posy;
        gen->posy += 1;
    }
}