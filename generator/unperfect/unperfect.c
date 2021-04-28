/*
** EPITECH PROJECT, 2020
** ant_man
** File description:
** main.c
*/

#include "../include/generator.h"
#include "../include/my.h"

void unperfect(gen_t *gen)
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
            check_left2(gen, x, y);
        if (y != 0)
            check_up2(gen, x, y);
        if (y != gen->y_max - 1)
            check_down2(gen, x, y);
        if (x != gen->x_max - 1)
            check_right2(gen, x, y);
        pop_wall(gen, x, y);
    }
    main_trail(gen);
}
