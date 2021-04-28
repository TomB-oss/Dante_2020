/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** describe all fonction
*/

#ifndef SOLVER_H
#define SOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>

typedef struct solver_s {
    char **tab;
    int height;
    int width;
    int x;
    int y;
} solver_t;

char **recursive(solver_t *solver, int x, int y);
void free_map(char **array);
void print_map(char **tab);
void print_map_visible(char **tab);
char **read_map(char *filename);
void took_off(solver_t *solver);

int surrounding_cell_up_left(solver_t *gen, int x, int y);
int surrounding_cell_down_left(solver_t *gen, int x, int y);
int surrounding_cell_up_right(solver_t *gen, int x, int y);
int surrounding_cell_down_right(solver_t *gen, int x, int y);

int surrounding_cell_left(solver_t *gen, int x, int y);
int surrounding_cell_right(solver_t *gen, int x, int y);
int surrounding_cell_down(solver_t *gen, int x, int y);
int surrounding_cell_up(solver_t *gen, int x, int y);
int surrounding_cell(solver_t *gen, int x, int y);

int get_heights(solver_t *solver);
int get_width(solver_t *solver);
void took_e_off(solver_t *solver);

#endif /*SOLVER_H*/
