/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** str_to_word_array.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *my_strncpy(char *dest, char const *src, int n);

int check_sep(char const *sep, char c)
{
    for (int u = 0; sep[u] != '\0'; u++) {
        if (sep[u] == c) {
            return (0);
        }
    }
    return (1);
}

int norme(char const *str, char const *sep, int a, int i)
{
    if (str[i] == sep[a] && str[i + 1] != '\0' && \
    check_sep(sep, str[i + 1]) == 1) {
        return (1);
    } else {
        return (0);
    }
}

int get_nb_words(const char *str, const char *separator)
{
    int count = 1;
    int i = 0;
    int a = 0;

    for (; str[i] != '\0'; i++) {
        for (; separator[a] != '\0'; a++) {
            count += norme(str, separator, a, i);
        }
        a = 0;
    }
    return (count);
}

int count_size_one_word(char const *str, char const *sep, int n, int count)
{
    int index = 0;

    for (; sep[index] != '\0'; index++) {
        if (str[n] == sep[index]) {
            return (count);
        } else if (str[n + 1] == '\0') {
            return (count + 1);
        }
    }
    return (0);
}

char **my_str_to_word_array(char const *str, const char *sep)
{
    int nb_word = get_nb_words(str, sep);
    char **word_array = malloc(sizeof(char *) * (nb_word + 1));
    int i = 0;
    int c = 0;

    for (int count = 0, l = 0, s = 0; str[i] != '\0' ; i++, count++) {
        s = count_size_one_word(str, sep, i, count);
        if (s > 0) {
            word_array[c] = malloc(sizeof(char) * (s + 1));
            my_strncpy(word_array[c], str + l, s);
            word_array[c][s] = '\0';
            if (word_array[c] == NULL)
                return (NULL);
            c++;
            l = l + (s + 1);
            count = -1;
        }
    }
    word_array[nb_word] = NULL;
    return (word_array);
}

