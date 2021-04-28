/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** reproduce my_strncmp
*/

#include "my.h"
#include <stdio.h>

int my_strncmp( char const *s1, char const *s2, int n)
{
    int i = 0;
    int lenght1 = my_strlen(s1);
    int lenght2 = my_strlen(s2);

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] == s2[i] && n > 0)
            i++;
            n--;
        if (s1[i] != s2[i] && lenght1 > lenght2)
            return (-1);
        if (s1[i] != s2[i] && lenght2 > lenght1)
            return (-1);
        i++;
        n--;
    }
    return (0);
}