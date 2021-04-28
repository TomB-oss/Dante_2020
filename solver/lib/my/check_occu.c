/*
** EPITECH PROJECT, 2020
** ant_man
** File description:
** main.c
*/

#include <stdlib.h>

int *check_occ(char *str)
{

    int *final = malloc(sizeof(int) * 127);
    char useless = 'a';

    if (str == NULL)
        return (final);
    for (int i = 0, j = 0; str[i] != '\0'; i++) {
        j = str[i];
        final[j] += 1;
    }
    return (final);
}