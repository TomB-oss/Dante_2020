/*
** EPITECH PROJECT, 2020
** ant_man
** File description:
** main.c
*/

#include "../include/generator.h"
#include "../include/my.h"

void init_list_chained(gen_t *gen)
{
    gen->map[gen->starting_y][gen->starting_x] = gen->cell;
    add_back(gen->walls, gen->starting_x - 1, gen->starting_y);
    add_back(gen->walls, gen->starting_x, gen->starting_y - 1);
    add_back(gen->walls, gen->starting_x, gen->starting_y + 1);
    add_back(gen->walls, gen->starting_x + 1, gen->starting_y);

    gen->map[gen->starting_y][gen->starting_x - 1] = 'X';
    gen->map[gen->starting_y - 1][gen->starting_x] = 'X';
    gen->map[gen->starting_y + 1][gen->starting_x] = 'X';
    gen->map[gen->starting_y][gen->starting_x + 1] = 'X';
}

void perfect1(gen_t *gen)
{
    int random = 0;
    int x = 0;
    int y = 0;

    init_list_chained(gen);
    while (gen->walls->first != NULL) {
        random = rand() % list_size(gen->walls);
        x = get_x_from_list(gen->walls, random);
        y = get_y_from_list(gen->walls, random);
        if (x != 0)
            check_left(gen, x, y);
        if (y != 0)
            check_up(gen, x, y);
        if (y != gen->y_max - 1)
            check_down(gen, x, y);
        if (x != gen->x_max - 1)
            check_right(gen, x, y);
        pop_wall(gen, x, y);
    }
    main_trail(gen);
}
