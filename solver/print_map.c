/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-bastien.boymond
** File description:
** print_map.c
*/

#include "include/solver.h"
#include "include/my.h"

int get_size_array(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return (i);
}

void print_map_visible(char **tab)
{
    int size = get_size_array(tab);

    for (int i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++) {
            if (tab[i][j] == 'o') {
                printf("\033[1;34m%c\033[0m", tab[i][j]);
            } else {
                printf("%c", tab[i][j]);
            }
        }
        if (i + 1 != size) {
            printf("\n");
        }
    }
}

void print_map(char **tab)
{
    int size = get_size_array(tab);

    for (int i = 0; tab[i]; i++) {
        for (int j = 0; tab[i][j]; j++) {
            printf("%c", tab[i][j]);
        }
        if (i + 1 != size) {
            printf("\n");
        }
    }
}
