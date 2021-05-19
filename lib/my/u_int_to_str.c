/*
** EPITECH PROJECT, 2020
** u_int_to_str
** File description:
** my_printf
*/
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

char *u_long_to_str_converter_two(int size_boucles,
    unsigned long fois_dix, unsigned long b)
{
    char *boucles;
    int i = 0;

    boucles = malloc(sizeof(char) * (size_boucles + 1));
    fois_dix = fois_dix / 10;
    while (fois_dix > 0) {
        boucles[i] = (b / fois_dix) + 48;
        b = b % fois_dix;
        i++;
        fois_dix = fois_dix / 10;
    }
    boucles[i] = '\0';
    return (boucles);
}

char *u_long_to_str_converter(unsigned long b)
{
    unsigned long fois_dix = 1;
    unsigned long b_bis = 0;
    int size_boucles = 0;
    char *zero = malloc(sizeof(char) * 2);

    if (b == 0) {
        zero[0] = '0';
        zero[1] = '\0';
        return (zero);
    }
    b_bis = b;
    while (b_bis > 0) { b_bis = b_bis / 10;
        fois_dix = fois_dix * 10;
        size_boucles++;
    }
    return (u_long_to_str_converter_two(size_boucles, fois_dix, b));
}
