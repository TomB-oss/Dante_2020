/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** reproduce the behavior of strcmp
*/

#include <stdio.h>
#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int lenght1 = my_strlen(s1);
    int lenght2 = my_strlen(s2);

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] == s2[i])
            i++;
        if (s1[i] != s2[i] && lenght1 > lenght2)
            return (-1);
        if (s1[i] != s2[i] && lenght2 > lenght1)
            return (-1);
        i++;
    }
    return (0);
}