/*
** EPITECH PROJECT, 2020
** finder
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char lenght_modifier(char *s, int i)
{
    if (s[i + 1] == 'h' && s[i + 2] == 'h')
        return ('H');
    if (s[i + 1] == 'l' && s[i + 2] == 'l')
        return ('L');
    if (s[i + 1] == 'h')
        return ('h');
    if (s[i + 1] == 'l')
        return ('l');
    if (s[i + 1] == 'q')
        return ('L');
    return (0);
}

char flag_finder(char *s, int i)
{
    if (s[i + 1] == '#')
        return ('#');
    if (s[i + 1] == '0')
        return ('0');
    if (s[i + 1] == '-')
        return ('-');
    if (s[i + 1] == ' ')
        return (' ');
    if (s[i + 1] == '+')
        return ('+');
    return (0);
}

int width_finder(char *s, int i)
{
    int size = 0;
    int ibis = i;
    int j = 0;
    int n = 0;
    char *nbr;

    while (s[ibis + 1] >= '0' && s[ibis + 1] <= '9') {
        size++;
        ibis++;
    }
    nbr = malloc(sizeof(char) * (size + 1));
    for (j = 0; j < (ibis - i); j++)
        nbr[j] = s[i + 1 + j];
    nbr[j] = '\0';
    n = my_getnbr(nbr);
    return (n);
}
