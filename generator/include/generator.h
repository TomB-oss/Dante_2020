/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** describe all fonction
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

typedef struct head_s
{
    struct wall_s *first;
} head_t;

typedef struct wall_s {
    int x;
    int y;
    struct wall_s *next;
} wall_t;

typedef struct gen_s
{
    int xend;
    int yend;
    int posx;
    int posy;
    int lastmovex;
    int lastmovey;
    int nbcase;
    char **map1;

    int starting_x;
    int starting_y;
    int x_max;
    int y_max;
    char wall;
    char cell;
    char unvisited;
    struct head_s *walls;
    char **map;
}gen_t;

void unperfect(gen_t *gen);

void perfect(gen_t *gen);

void printing_map(char **map);

char **create_map1(int x, int y);

void replace_u(gen_t *gen);

char **create_map(int x, int y);

int next_left(gen_t *gen);

int next_right(gen_t *gen);

int next_up(gen_t *gen);

int next_down(gen_t *gen);

void impaire(gen_t *gen, int i);

int get_size_array(char **array);

void paire(gen_t *gen, int i);

head_t *init_list(void);

void perfect1(gen_t *gen);

void printing_map(char **map);

void printing_map_visible(char **map);

char **create_map(int x, int y);

int free_list(head_t *list);

int add_back(head_t *l_a, int x, int y);

int print_list(head_t *list);

void free_array(char **array);

int list_size(head_t *list);

int pop_back(head_t *list);

int surrounding_cell(gen_t *gen, int x, int y);

void upper_cell(gen_t *gen, int x, int y);

void bottom_cell(gen_t *gen, int x, int y);

void left_cell(gen_t *gen, int x, int y);

void right_cell(gen_t *gen, int x, int y);

int surrounding_cell_up(gen_t *gen, int x, int y);

int surrounding_cell_down(gen_t *gen, int x, int y);

int pop_front(head_t *list);

int is_in_walls(gen_t *gen, int x, int y);

void pop_wall(gen_t *gen, int x, int y);

int get_y_from_list(head_t *list, int index);

int get_x_from_list(head_t *list, int index);

int get_wall(gen_t *gen);

void check_up(gen_t *gen, int x, int y);

void check_down(gen_t *gen, int x, int y);

void check_left(gen_t *gen, int x, int y);

void check_right(gen_t *gen, int x, int y);

void check_up2(gen_t *gen, int x, int y);

void check_down2(gen_t *gen, int x, int y);

void check_left2(gen_t *gen, int x, int y);

void init_list_chained(gen_t *gen);

void check_right2(gen_t *gen, int x, int y);
