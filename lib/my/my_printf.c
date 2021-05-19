/*
** EPITECH PROJECT, 2020
** main
** File description:
** myprintf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void my_printf_three(Main *pf, va_list *list)
{
    if ((*pf).s[(*pf).i] == '%' && (*pf).s[(*pf).i + 1] == 'b')
        (*pf).s = print_binary((*pf).s, (*pf).i,
        va_arg((*list), unsigned long), (*pf).nbr_btw, (*pf).flag, (*pf).width);
    if ((*pf).s[(*pf).i] == '%' && (*pf).s[(*pf).i + 1] == 'S')
        (*pf).s = print_string_octal((*pf).s, (*pf).i,
        va_arg((*list), char *), (*pf).flag, (*pf).width);
    if ((*pf).s[(*pf).i] == '%' && (*pf).s[(*pf).i + 1] == 'p') {
        (*pf).s[(*pf).i + 1] = 'x';
        (*pf).s = print_hexadecimal((*pf).s, (*pf).i,
        va_arg((*list), void *), (*pf).nbr_btw, 'l', '#', 0);
        (*pf).s = print_pointer((*pf).s, (*pf).i, (*pf).flag, (*pf).width);
    }
    if ((*pf).s[(*pf).i] == '%' && (*pf).s[(*pf).i + 1] == 'm')
        (*pf).s = print_string((*pf).s, (*pf).i,
        "Success", (*pf).flag, (*pf).width);
    if ((*pf).s[(*pf).i] == '%' && (*pf).s[(*pf).i + 1] == '%')
        (*pf).s = print_char((*pf).s, (*pf).i, '%', 0, 0);
}

void my_printf_two(Main *pf, va_list *list)
{
    if ((*pf).s[(*pf).i] == '%' && (*pf).s[(*pf).i + 1] == 'c')
        (*pf).s = print_char((*pf).s, (*pf).i,
        va_arg((*list), int), (*pf).flag, (*pf).width);
    if ((*pf).s[(*pf).i] == '%' && (*pf).s[(*pf).i + 1] == 's')
        (*pf).s = print_string((*pf).s, (*pf).i,
        va_arg((*list), char *), (*pf).flag, (*pf).width);
    if ((*pf).s[(*pf).i] == '%' &&
        ((*pf).s[(*pf).i + 1] == 'd' || (*pf).s[(*pf).i + 1] == 'i'))
        (*pf).s = print_int((*pf).s, (*pf).i,
        va_arg((*list), int), (*pf).nbr_btw,
        (*pf).ltr_btw, (*pf).flag, (*pf).width);
    if ((*pf).s[(*pf).i] == '%' && (*pf).s[(*pf).i + 1] == 'o')
        (*pf).s = print_octal((*pf).s, (*pf).i, va_arg((*list), unsigned long),
        (*pf).nbr_btw, (*pf).ltr_btw, (*pf).flag, (*pf).width);
    if ((*pf).s[(*pf).i] == '%' && (*pf).s[(*pf).i + 1] == 'u')
        (*pf).s = print_decimal((*pf).s, (*pf).i, va_arg((*list), unsigned int),
        (*pf).nbr_btw, (*pf).ltr_btw, (*pf).flag, (*pf).width);
    if ((*pf).s[(*pf).i] == '%' && ((*pf).s[(*pf).i + 1] == 'x' ||
        (*pf).s[(*pf).i + 1] == 'X')) (*pf).s = print_hexadecimal((*pf).s,
        (*pf).i, va_arg((*list), long long unsigned int),
        (*pf).nbr_btw, (*pf).ltr_btw, (*pf).flag, (*pf).width);
}

void my_printf_one(Main *pf)
{
    (*pf).nbr_btw = 0;
    (*pf).width = 0;
    if ((*pf).s[(*pf).i] == '%' && (*pf).s[(*pf).i - 1] != '%') {
        (*pf).flag = flag_finder((*pf).s, (*pf).i);
        (*pf).s = s_without_flag((*pf).s, (*pf).i);
        (*pf).width = width_finder((*pf).s, (*pf).i);
        (*pf).s = s_without_width((*pf).s, (*pf).i);
        (*pf).nbr_btw = precision((*pf).s, (*pf).i);
        (*pf).s = s_without_between((*pf).s, (*pf).i);
        (*pf).ltr_btw = lenght_modifier((*pf).s, (*pf).i);
        (*pf).s = s_without_between2((*pf).s, (*pf).i);
    }
}

void *my_printf(char *str, ...)
{
    va_list list;
    Main pf;

    pf.i = 0;
    pf.s = my_strdup(str);
    va_start(list, str);
    while (pf.s[pf.i] != '\0') {
        my_printf_one(&pf);
        my_printf_two(&pf, &list);
        my_printf_three(&pf, &list);
        pf.i++;
    }
    va_end(list);
    my_putstr(pf.s);
    return (pf.s);
}
