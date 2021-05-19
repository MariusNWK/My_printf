/*
** EPITECH PROJECT, 2020
** print_char_nbr
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void print_char_nbr_three(char *s, Value *cn)
{
    if ((*cn).flag == '-') {
        while ((*cn).width > 0) {
            (*cn).new_s[(*cn).k] = ' ';
            (*cn).k++;
            (*cn).width--;
        }
    }
    while (s[(*cn).i + 2] != '\0') {
        (*cn).new_s[(*cn).k] = s[(*cn).i + 2];
        (*cn).i++;
        (*cn).k++;
    }
    (*cn).new_s[(*cn).k] = '\0';
}

void print_char_nbr_two(Value *cn)
{
    if ((*cn).flag != '-') {
        while ((*cn).width > 0) {
            (*cn).new_s[(*cn).k] = ' ';
            (*cn).k++;
            (*cn).width--;
        }
    }
    if ((*cn).nbr[0] != '0' || my_strlen((*cn).nbr) != 1 ||
        (*cn).nbr_btw != 0) {
        for (; (*cn).zeros > 0; (*cn).zeros--, (*cn).k++)
            (*cn).new_s[(*cn).k] = '0';
        for (; (*cn).nbr[(*cn).p] != '\0';
            (*cn).p++, (*cn).k++)
            (*cn).new_s[(*cn).k] = (*cn).nbr[(*cn).p];
    }
}

void print_char_nbr_one(char *s, Value *cn)
{
    (*cn).k = 0;
    (*cn).p = 0;
    (*cn).zeros = (*cn).nbr_btw - my_strlen((*cn).nbr);
    (*cn).width = (*cn).width - my_strlen((*cn).nbr);
    if ((*cn).zeros > 0) (*cn).width = (*cn).width - (*cn).zeros;
    if ((*cn).width < 0) (*cn).width = 0;
    if ((*cn).zeros > 0)
        (*cn).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + my_strlen((*cn).nbr) +
        (*cn).zeros + (*cn).width));
    else if (my_strlen((*cn).nbr) == 1 &&
        (*cn).nbr[0] == '0' && (*cn).nbr_btw == 0)
        (*cn).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + (*cn).width));
    else (*cn).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + my_strlen((*cn).nbr) +
        (*cn).width));
    while ((*cn).k < (*cn).i) {
        (*cn).new_s[(*cn).k] = s[(*cn).k];
        (*cn).k++;
    }
}

char *print_char_nbr(char *s, ...)
{
    va_list list7;
    Value cn;

    va_start(list7, s);
    cn.i = va_arg(list7, int);
    cn.nbr = va_arg(list7, char *);
    cn.nbr_btw = va_arg(list7, int);
    cn.flag = va_arg(list7, int);
    cn.width = va_arg(list7, int);
    va_end(list7);
    print_char_nbr_one(s, &cn);
    print_char_nbr_two(&cn);
    print_char_nbr_three(s, &cn);
    free(cn.nbr);
    free(s);
    return (cn.new_s);
}
