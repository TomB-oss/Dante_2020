/*
** EPITECH PROJECT, 2020
** ant_man
** File description:
** main.c
*/

#include "include/solver.h"
#include "include/my.h"

int map_solver_bis(solver_t *map, int i, int j)
{
    if (map_solver(map, i, j + 1) == 0) {
        map->tab[i][j] = 'o';
        return (0);
    }
    if (map_solver(map, i - 1, j) == 0) {
        map->tab[i][j] = 'o';
        return (0);
    }
    if (map_solver(map, i, j - 1) == 0) {
        map->tab[i][j] = 'o';
        return (0);
    }
    return (1);
}

int	map_solver(solver_t *map, int i, int j)
{
    if (i > map->height || j > map->width || i < 0 || j < 0 || \
    map->tab[i][j] != '*') {
        return (1);
    }
    map->tab[i][j] = 'e';
    if (i == map->height && j == map->width) {
        map->tab[i][j] = 'o';
        return (0);
    }
    if (map_solver(map, i + 1, j) == 0) {
        map->tab[i][j] = 'o';
        return (0);
    }
    if (map_solver_bis(map, i, j) == 0) {
        return (0);
    }
    return (1);
}

void get_smallest_path_bis(solver_t *solver)
{
    if (solver->tab[solver->y - 1][solver->x] == 'o') {
        solver->y -= 1;
        solver->tab[solver->y][solver->x] = 'i';
    } else if (solver->tab[solver->y][solver->x - 1] == 'o') {
        solver->x -= 1;
        solver->tab[solver->y][solver->x] = 'i';
    }
}

void get_smallest_path(solver_t *solver)
{
    solver->x = 0;
    solver->y = 0;

    solver->tab[solver->y][solver->x] = 'i';
    while (solver->x != solver->width && solver->y != solver->height) {
        if (solver->tab[solver->y][solver->x + 1] == 'o') {
            solver->x += 1;
            solver->tab[solver->y][solver->x] = 'i';
        } else if (solver->tab[solver->y + 1][solver->x] == 'o') {
            solver->y += 1;
            solver->tab[solver->y][solver->x] = 'i';
        } else {
            get_smallest_path_bis(solver);
        }
    }
    solver->tab[solver->height][solver->width] = 'i';
}

void print_help()
{
    my_printf("Usage:\n");
    my_printf("     ./solver/solver file\n\n");
    
    my_printf("Description:\n");
    my_printf("      Solve a maze (perfect or not)\n");
    
}

int main(int argc, char **argv)
{
    solver_t *solver = malloc(sizeof(solver_t));

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        print_help();
        exit(0);
    }
    solver->tab = read_map(argv[1]);

    solver->height = get_heights(solver);
    solver->width = get_width(solver);
    map_solver(solver, 0, 0);
    get_smallest_path(solver);
    took_off(solver);
    print_map_visible(solver->tab);
    free_map(solver->tab);
    free(solver);
    return (0);
}