/*
** EPITECH PROJECT, 2020
** length_conver_long_u
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

long long unsigned int length_converter_long_u
    (long long unsigned int n, char ltr_btw)
{
    unsigned char c = n;
    unsigned short sh = n;
    unsigned long g = n;
    unsigned long long gg = n;

    if (ltr_btw == 'H')
        return (c);
    if (ltr_btw == 'h')
        return (sh);
    if (ltr_btw == 'l')
        return (g);
    if (ltr_btw == 'L')
        return (gg);
    if (ltr_btw == 'q')
        return (gg);
}
