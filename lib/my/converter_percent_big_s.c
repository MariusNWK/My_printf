/*
** EPITECH PROJECT, 2020
** converter_percent_big_s
** File description:
** my_printf
*/
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *converter_percent_big_s(int ascii)
{
    char *nbr = malloc(sizeof(char) * 4);
    char *asc = int_to_str_converter(ascii);
    int size_ascii = 0;
    int asciibis = ascii;
    int zeros = 0;
    int i = 0;

    while (asciibis > 0) { asciibis = asciibis / 10;
        size_ascii++;
    }
    zeros = 3 - size_ascii;
    while (zeros > 0) {
        nbr[i] = '0';
        zeros--;
        i++;
    }
    for (int j = 0; size_ascii > 0; i++, j++, size_ascii--)
        nbr[i] = asc[j];
    nbr[i] = '\0';
    free(asc);
    return (nbr);
}
