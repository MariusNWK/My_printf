/*
** EPITECH PROJECT, 2020
** print_char2
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void print_int_six(char *s, Value *in)
{
    if ((*in).flag == '-')
        minor_resolver_int(in);
    while (s[(*in).i + 2] != '\0') {
        (*in).new_s[(*in).k] = s[(*in).i + 2];
        (*in).i++;
        (*in).k++;
    }
    (*in).new_s[(*in).k] = '\0';
}

void print_int_five(Value *in)
{
    if ((*in).n != 0 || (*in).nbr_btw != 0) {
        if ((*in).nbr[0] == '-') {
            if ((*in).flag == '0')
                (*in).new_s[(*in).k] = '0';
            else
                (*in).new_s[(*in).k] = '-';
            (*in).k++;
            (*in).p = (*in).p + 1;
        }
        for (; (*in).zeros > 0; (*in).zeros--, (*in).k++)
            (*in).new_s[(*in).k] = '0';
        for (; (*in).nbr[(*in).p] != '\0'; (*in).p++, (*in).k++)
            (*in).new_s[(*in).k] = (*in).nbr[(*in).p];
    }
}

void print_int_four(Value *in)
{
    if ((*in).flag != '-') {
        while ((*in).widthbis > 0) {
            if ((*in).widthbis == (*in).width &&
                (*in).nbr[0] == '-' && (*in).flag == '0')
                (*in).new_s[(*in).k] = '-';
            else if ((*in).flag == '0')
                (*in).new_s[(*in).k] = '0';
            else
                (*in).new_s[(*in).k] = ' ';
            (*in).k++;
            (*in).widthbis--;
        }
    }
    if ((*in).flag == ' ' || (*in).flag == '+') {
        (*in).new_s[(*in).k] = (*in).flag;
        (*in).k = (*in).k + 1;
    }
}
