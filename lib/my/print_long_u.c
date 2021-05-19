/*
** EPITECH PROJECT, 2020
** print_long_u
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void print_long_u_four(char *s, Ulong *lu)
{
    if ((*lu).flag == '-')
        minor_resolver_long(lu);
    while (s[(*lu).i + 2] != '\0') {
        (*lu).new_s[(*lu).k + (*lu).f] = s[(*lu).i + 2];
        (*lu).i++;
        (*lu).k++;
    }
    (*lu).new_s[(*lu).k + (*lu).f] = '\0';
}

void print_long_u_three(Ulong *lu)
{
    if ((*lu).flag != '-') {
        while ((*lu).widthbis > 0) {
            if ((*lu).flag == '0')
                (*lu).new_s[(*lu).k] = '0';
            else
                (*lu).new_s[(*lu).k] = ' ';
            (*lu).k++;
            (*lu).widthbis--;
        }
    }
    if ((*lu).n != 0 || (*lu).nbr_btw != 0) {
        if ((*lu).flag == '#')
            (*lu).new_s[(*lu).k] = '0';
        for (; (*lu).zeros > 0; (*lu).zeros--, (*lu).k++)
            (*lu).new_s[(*lu).k + (*lu).f] = '0';
        for (; (*lu).nbr[(*lu).p] != '\0'; (*lu).p++, (*lu).k++)
            (*lu).new_s[(*lu).k + (*lu).f] = (*lu).nbr[(*lu).p];
    }
}

void print_long_u_two(char *s, Ulong *lu)
{
    if ((*lu).zeros > 0)
        (*lu).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + my_strlen((*lu).nbr) +
        (*lu).zeros + (*lu).width));
    else if ((*lu).n == 0 && (*lu).nbr_btw == 0)
        (*lu).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + (*lu).width));
    else
        (*lu).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + my_strlen((*lu).nbr) +
        (*lu).f + (*lu).width));
    while ((*lu).k < (*lu).i) {
        (*lu).new_s[(*lu).k] = s[(*lu).k];
        (*lu).k++;
    }
    (*lu).widthbis = (*lu).width;
}

void print_long_u_one(Ulong *lu)
{
    (*lu).zeros = 0;
    (*lu).k = 0;
    (*lu).p = 0;
    (*lu).f = 0;
    if ((*lu).flag == '0' && (*lu).nbr_btw > 0)
        (*lu).flag = 0;
    (*lu).nbr = u_long_to_str_converter((*lu).n);
    (*lu).zeros = (*lu).nbr_btw - my_strlen((*lu).nbr);
    if ((*lu).flag == '#' && (*lu).zeros <= 0)
        (*lu).f = (*lu).f + 1;
    (*lu).width = (*lu).width - my_strlen((*lu).nbr) - (*lu).f;
    if ((*lu).zeros > 0)
        (*lu).width = (*lu).width - (*lu).zeros;
    if ((*lu).width < 0)
        (*lu).width = 0;
}

char *print_long_u(char *s, ...)
{
    va_list list5;
    Ulong lu;

    va_start(list5, s);
    lu.i = va_arg(list5, int);
    lu.n = va_arg(list5, long long unsigned int);
    lu.nbr_btw = va_arg(list5, int);
    lu.flag = va_arg(list5, int);
    lu.width = va_arg(list5, int);
    va_end(list5);
    print_long_u_one(&lu);
    print_long_u_two(s, &lu);
    print_long_u_three(&lu);
    print_long_u_four(s, &lu);
    free(lu.nbr);
    free(s);
    return (lu.new_s);
}
