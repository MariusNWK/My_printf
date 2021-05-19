/*
** EPITECH PROJECT, 2020
** print_octal
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *print_octal(char *s, ...)
{
    va_list list3;
    int i = 0;
    unsigned long n = 0;
    int nbr_btw = 0;
    char ltr_btw;
    char flag;
    int width = 0;

    va_start(list3, s);
    i = va_arg(list3, int);
    n = va_arg(list3, long long unsigned int);
    nbr_btw = va_arg(list3, int);
    ltr_btw = va_arg(list3, int);
    flag = va_arg(list3, int);
    width = va_arg(list3, int);
    va_end(list3);
    n = length_converter_long_u(n, ltr_btw);
    n = base_converter(n, 8);
    return (print_long_u(s, i, n, nbr_btw, flag, width));
}
