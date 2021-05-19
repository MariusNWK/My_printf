/*
** EPITECH PROJECT, 2020
** precision
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int precision(char *s, int i)
{
    int result = 0;
    char *between;
    int ibis = 0;
    int j = 0;
    int k = 0;

    for (j = i + 1; (s[j] < 'a' || s[j] > 'z') &&
        (s[j] < 'A' || s[j] > 'Z') && (s[j] != '%'); j++);
    if ((j - i) > 1) {
        between = malloc(sizeof(char) * (j - i - 1 - 1 + 1));
        ibis = i;
        for (k = 0; k < (j - ibis - 1 - 1); k++, i++) {
            between[k] = s[i + 2];
        }
        between[k] = '\0';
        result = my_getnbr(between);
        free(between);
        return (result);
    }
    else
        return (-1);
}
