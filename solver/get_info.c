/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-bastien.boymond
** File description:
** get_info.c
*/

#include "include/solver.h"
#include "include/my.h"

void took_e_off(solver_t *solver)
{

    for (int y = 0; solver->tab[y] != NULL; y++) {
        for (int x = 0; solver->tab[y][x] != '\0'; x++) {
            if (solver->tab[y][x] == 'e') {
                solver->tab[y][x] = '*';
            }
        }
    }
}

void took_off(solver_t *solver)
{

    for (int y = 0; solver->tab[y] != NULL; y++) {
        for (int x = 0; solver->tab[y][x] != '\0'; x++) {
            if (solver->tab[y][x] == 'e') {
                solver->tab[y][x] = '*';
            }
            if (solver->tab[y][x] == 'o') {
                solver->tab[y][x] = '*';
            }
            if (solver->tab[y][x] == 'i') {
                solver->tab[y][x] = 'o';
            }
        }
    }
}

int get_heights(solver_t *solver)
{
    int y = 0;

    for (; solver->tab[y] != NULL; y++);
    y--;
    return (y);
}

int get_width(solver_t *solver)
{
    int x = 0;

    for (; solver->tab[0][x] != '\0'; x++);
    x--;
    return (x);
}