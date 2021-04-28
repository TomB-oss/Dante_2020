/*
** EPITECH PROJECT, 2020
** ant_man
** File description:
** main.c
*/

#include "include/generator.h"
#include "include/my.h"

static void change_starring_point(gen_t *gen)
{
    if (gen->starting_y == 0) {
        gen->starting_y += 1;
    }
    if (gen->starting_y == gen->y_max - 1) {
        gen->starting_y -= 1;
    }
    if (gen->starting_x == 0) {
        gen->starting_x += 1;
    }
    if (gen->starting_x == gen->x_max - 1) {
        gen->starting_x -= 1;
    }
}

static void init_bis(gen_t *gen, char **argv)
{
    gen->walls = init_list();
    gen->x_max = atoi(argv[1]);
    gen->y_max = atoi(argv[2]);
    gen->cell = '*';
    gen->unvisited = 'u';
    gen->wall = 'X';
    gen->starting_x = rand() % gen->x_max;
    gen->starting_y = rand() % gen->y_max;
    gen->map = create_map(gen->x_max, gen->y_max);
    change_starring_point(gen);
}

static gen_t *fill_args(char **argv)
{
    gen_t *gen = malloc(sizeof(gen_t));

    gen->xend = atoi(argv[1]);
    gen->yend = atoi(argv[2]);
    gen->posx = 0;
    gen->posy = 0;
    gen->lastmovex = -1;
    gen->lastmovey = -1;
    gen->nbcase = gen->xend * gen->yend;
    gen->map1 = create_map1(gen->xend, gen->yend);
    gen->xend--;
    gen->yend--;
    init_bis(gen, argv);
    return (gen);
}

void print_help()
{
    my_printf("Usage:\n");
    my_printf("     ./generator/generator SIZE Y SIZE X [perf]\n\n");
    
    my_printf("Description:\n");
    my_printf("      Create a maze (perfect or not)\n");
    
}

void free_all(gen_t *gen)
{
    free_list(gen->walls);
    free_array(gen->map1);
    free_array(gen->map);
    free(gen);
}

int main(int argc, char **argv)
{
    gen_t *gen = NULL;

    srand(time(NULL));
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        print_help();
    if (argc < 3)
        exit(0);
    gen = fill_args(argv);
    if (argc < 4) {
        unperfect(gen);
        replace_u(gen);
        printing_map(gen->map);
    } else if (my_strcmp(argv[3], "perf") == 0){
        perfect1(gen);
        replace_u(gen);
        printing_map(gen->map);
    }
    free_all(gen);
    return (0);
}