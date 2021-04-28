/*
** EPITECH PROJECT, 2020
** ant_man
** File description:
** main.c
*/

#include "include/generator.h"
#include "include/my.h"

int get_size_array(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return (i);
}

void printing_map(char **map)
{
    int size = get_size_array(map);

    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            printf("%c", map[i][j]);
        }
        if (i + 1 != size) {
            printf("\n");
        }
    }
}

static char **map_memset(char **map, char c, int x, int y)
{
    for (int i = 0 ; i < y ; i++) {
        for (int j = 0 ; j < x ; j++) {
            map[i][j] = c;
        }
        map[i][x] = '\0';
    }
    return (map);
}

char **create_map1(int x, int y)
{
    char **map = malloc(sizeof(char *) * (y + 1));

    for (int i = 0; i < y; i++) {
        if (i != y - 1)
            map[i] = malloc(sizeof(char) * (x + 2));
        else
            map[i] = malloc(sizeof(char) * (x + 1));
    }
    map[y] = NULL;
    map = map_memset(map, 'X', x, y);
    map[0][0] = '*';
    map[y - 1][x - 1] = '*';
    return (map);
}

char **create_map(int x, int y)
{
    char **map = malloc(sizeof(char *) * (y + 1));

    for (int i = 0; i < y; i++) {
        if (i != y - 1)
            map[i] = malloc(sizeof(char) * (x + 2));
        else
            map[i] = malloc(sizeof(char) * (x + 1));
    }
    map[y] = NULL;
    map = map_memset(map, 'u', x, y);
    return (map);
}