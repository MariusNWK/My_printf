/*
** EPITECH PROJECT, 2020
** binary_converter
** File description:
** my_printf
*/
#include <stdio.h>
#include "my.h"
#include <stdlib.h>

char *binary_converter(long long unsigned int n)
{
    char *result;
    int i = 0;
    unsigned int size = 0;
    long long unsigned int n_bis = n;

    while (n_bis > 0) {
        n_bis = n_bis / 2;
        size++;
    }
    size = size + 1;
    result = malloc(sizeof(char) * (size + 1));
    if (n == 2)
        return (my_strdup("10"));
    for (i = 0; n > 0; i++) {
        result[i] = (n % 2) + 48;
        n = n / 2;
    }
    result = my_revstr(result);
    result[i] = '\0';
    return (result);
}
