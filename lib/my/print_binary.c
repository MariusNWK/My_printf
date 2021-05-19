/*
** EPITECH PROJECT, 2020
** print_binary
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *print_binary(char *s, ...)
{
    va_list list6;
    int i = 0;
    unsigned long n = 0;
    int nbr_btw = 0;
    int width = 0;
    int flag = 0;
    char *nbr;

    va_start(list6, s);
    i = va_arg(list6, int);
    n = va_arg(list6, long long unsigned int);
    nbr_btw = va_arg(list6, int);
    flag = va_arg(list6, int);
    width = va_arg(list6, int);
    va_end(list6);
    nbr = binary_converter(n);
    return (print_char_nbr(s, i, nbr, nbr_btw, flag, width));
}
