/*
** EPITECH PROJECT, 2020
** print_decimal
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *print_decimal(char *s, ...)
{
    va_list list4;
    int i = 0;
    unsigned int n = 0;
    int nbr_btw = 0;
    int flag = 0;
    int width = 0;
    char ltr_btw;

    va_start(list4, s);
    i = va_arg(list4, int);
    n = va_arg(list4, unsigned int);
    nbr_btw = va_arg(list4, int);
    ltr_btw = va_arg(list4, int);
    flag = va_arg(list4, int);
    width = va_arg(list4, int);
    va_end(list4);
    if (flag != '0' && flag != '-')
        flag = 0;
    n = length_converter_int_u(n, ltr_btw);
    return (print_long_u(s, i, n, nbr_btw, flag, width));
}
