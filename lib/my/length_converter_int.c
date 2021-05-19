/*
** EPITECH PROJECT, 2020
** length_converter_int
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *length_converter_int(int n, char ltr_btw)
{
    char c = n;
    short sh = n;
    long g = n;
    long long gg = n;

    if (ltr_btw == 'H')
        return (int_to_str_converter(c));
    if (ltr_btw == 'h')
        return (int_to_str_converter(sh));
    if (ltr_btw == 'l')
        return (int_to_str_converter(g));
    if (ltr_btw == 'L')
        return (int_to_str_converter(gg));
    if (ltr_btw == 'q')
        return (int_to_str_converter(gg));
}
