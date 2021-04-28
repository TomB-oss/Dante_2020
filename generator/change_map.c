/*
** EPITECH PROJECT, 2020
** generator
** File description:
** change_map.c
*/

#include "include/generator.h"
#include "include/my.h"

void replace_u(gen_t *gen)
{
    for (int y = 0; gen->map[y] != NULL; y++) {
        for (int x = 0; gen->map[y][x] != '\0'; x++) {
            if (gen->map[y][x] == 'u') {
                gen->map[y][x] = 'X';
            }
        }
    }
}

head_t *init_list(void)
{
    head_t *l_a = malloc(sizeof(*l_a));

    l_a->first = NULL;
    return (l_a);
}
