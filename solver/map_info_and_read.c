/*
** EPITECH PROJECT, 2020
** B-CPE-200-MPL-2-1-dante-bastien.boymond
** File description:
** map_info.c
*/

#include "include/solver.h"
#include "include/my.h"

char **read_map(char *filename)
{
    char **tab = NULL;
    char *map = NULL;
    ssize_t ret = 0;
    int fd = open(filename, O_RDONLY);
    struct stat st;

    stat(filename, &st);
    map = malloc(sizeof(char) * st.st_size + 1);
    ret = read(fd, map, st.st_size);
    map[ret] = '\0';
    if (ret < 0) {
        exit (84);
    }
    tab = my_str_to_word_array(map, "\n");
    free(map);
    close(fd);
    return (tab);
}

void free_map(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    return (0);
}
