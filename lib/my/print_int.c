/*
** EPITECH PROJECT, 2020
** print_int
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void print_int_three(char *s, Value *in)
{
    if ((*in).zeros > 0)
        (*in).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + my_strlen((*in).nbr) +
        (*in).zeros + (*in).width + (*in).f));
    else if ((*in).n == 0 && (*in).nbr_btw == 0)
        (*in).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + (*in).width + (*in).f));
    else
        (*in).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + my_strlen((*in).nbr) + (*in).width + (*in).f));
    while ((*in).k < (*in).i) {
        (*in).new_s[(*in).k] = s[(*in).k];
        (*in).k++;
    }
    (*in).widthbis = (*in).width;
}

void print_int_two(Value *in)
{
    if ((*in).ltr_btw == 0)
        (*in).nbr = int_to_str_converter((*in).n);
    else
        (*in).nbr = length_converter_int((*in).n, (*in).ltr_btw);
    if (((*in).flag == ' ' && (*in).nbr[0] == '-') ||
        ((*in).flag == '+' && (*in).nbr[0] == '-'))
        (*in).flag = 0;
    if ((*in).flag == ' ')
        (*in).f = (*in).f + 1;
    (*in).zeros = (*in).nbr_btw - my_strlen((*in).nbr);
    (*in).width = (*in).width - my_strlen((*in).nbr);
    if ((*in).flag == '+')
        (*in).width = (*in).width - 1;
    if ((*in).width < 0)
        (*in).width = 0;
    if ((*in).nbr[0] == '-')
        (*in).zeros = (*in).zeros + 1;
    if ((*in).zeros > 0)
        (*in).width = (*in).width - (*in).zeros;
}

void print_int_one(Value *in)
{
    if ((*in).nbr_btw > 0 && (*in).flag == '0')
        (*in).flag = 0;
    if ((*in).flag == ' ' && (*in).width > 0)
        (*in).flag = 0;
    (*in).p = 0;
    (*in).f = 0;
    (*in).k = 0;
    (*in).zeros = 0;
}

char *print_int(char *s, ...)
{
    va_list list2;
    Value in;

    va_start(list2, s);
    in.i = va_arg(list2, int);
    in.n = va_arg(list2, int);
    in.nbr_btw = va_arg(list2, int);
    in.ltr_btw = va_arg(list2, int);
    in.flag = va_arg(list2, int);
    in.width = va_arg(list2, int);
    va_end(list2);
    print_int_one(&in);
    print_int_two(&in);
    print_int_three(s, &in);
    print_int_four(&in);
    print_int_five(&in);
    print_int_six(s, &in);
    free(in.nbr);
    free(s);
    return (in.new_s);
}
