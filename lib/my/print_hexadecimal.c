/*
** EPITECH PROJECT, 2020
** print_hexadecimal
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void print_hexadecimal_four(char *s, Ulong *ph)
{
    if ((*ph).flag == '-')
        minor_resolver_hexa(ph);
    while (s[(*ph).i + 2] != '\0') {
        (*ph).new_s[(*ph).k + (*ph).f] = s[(*ph).i + 2];
        (*ph).i++;
        (*ph).k++;
    }
    (*ph).new_s[(*ph).k + (*ph).f] = '\0';
}

void print_hexadecimal_three(Ulong *ph)
{
    if ((*ph).flag != '-') {
        while ((*ph).widthbis > 0) {
            if ((*ph).flag == '0')
                (*ph).new_s[(*ph).k] = '0';
            else
                (*ph).new_s[(*ph).k] = ' ';
            (*ph).k++;
            (*ph).widthbis--;
        }
    }
    if (my_strlen((*ph).nbr) != 1 ||
        (*ph).nbr[0] != '0' || (*ph).nbr_btw != 0) {
        if ((*ph).f == 2) {
            (*ph).new_s[(*ph).k] = '0';
            (*ph).new_s[(*ph).k + 1] = 'x';
        }
        for (; (*ph).zeros > 0; (*ph).zeros--, (*ph).k++)
            (*ph).new_s[(*ph).k + (*ph).f] = '0';
        for (; (*ph).nbr[(*ph).p] != '\0'; (*ph).p++, (*ph).k++)
            (*ph).new_s[(*ph).k + (*ph).f] = (*ph).nbr[(*ph).p];
    }
}

void print_hexadecimal_two(char *s, Ulong *ph)
{
    if ((*ph).zeros > 0)
        (*ph).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + my_strlen((*ph).nbr) +
        (*ph).zeros + (*ph).f + (*ph).width));
    else if (my_strlen((*ph).nbr) == 1 &&
        (*ph).nbr[0] == '0' && (*ph).nbr_btw == 0)
        (*ph).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + (*ph).width));
    else
        (*ph).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + my_strlen((*ph).nbr) +
        (*ph).f + (*ph).width));
    while ((*ph).k < (*ph).i) {
        (*ph).new_s[(*ph).k] = s[(*ph).k];
        (*ph).k++;
    }
    (*ph).widthbis = (*ph).width;
}

void print_hexadecimal_one(char *s, Ulong *ph)
{
    (*ph).zeros = 0;
    (*ph).k = 0;
    (*ph).p = 0;
    (*ph).f = 0;
    if ((*ph).flag == '0' && (*ph).nbr_btw > 0)
        (*ph).flag = 0;
    (*ph).n = length_converter_int_u((*ph).n, (*ph).ltr_btw);
    if (s[(*ph).i + 1] == 'x')
        (*ph).nbr = hexa_converter((*ph).n, 'x');
    else
        (*ph).nbr = hexa_converter((*ph).n, 'X');
    if ((*ph).flag == '#')
        (*ph).f = 2;
    (*ph).zeros = (*ph).nbr_btw - my_strlen((*ph).nbr);
    (*ph).width = (*ph).width - my_strlen((*ph).nbr) - (*ph).f;
    if ((*ph).zeros > 0)
        (*ph).width = (*ph).width - (*ph).zeros;
    if ((*ph).width < 0)
        (*ph).width = 0;
}

char *print_hexadecimal(char *s, ...)
{
    va_list list5;
    Ulong ph;

    va_start(list5, s);
    ph.i = va_arg(list5, int);
    ph.n = va_arg(list5, long long unsigned int);
    ph.nbr_btw = va_arg(list5, int);
    ph.ltr_btw = va_arg(list5, int);
    ph.flag = va_arg(list5, int);
    ph.width = va_arg(list5, int);
    va_end(list5);
    print_hexadecimal_one(s, &ph);
    print_hexadecimal_two(s, &ph);
    print_hexadecimal_three(&ph);
    print_hexadecimal_four(s, &ph);
    free(ph.nbr);
    free(s);
    return (ph.new_s);
}
