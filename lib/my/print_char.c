/*
** EPITECH PROJECT, 2020
** print_char
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void print_char_three(char *s, Value *ch)
{
    (*ch).new_s[(*ch).k] = (*ch).c;
    (*ch).k = (*ch).k + 1;
    if ((*ch).flag == '-') {
        while ((*ch).width > 0) {
            (*ch).new_s[(*ch).k] = ' ';
            (*ch).k++;
            (*ch).width--;
        }
    }
    while (s[(*ch).i + 2] != '\0') {
        (*ch).new_s[(*ch).k] = s[(*ch).i + 2];
        (*ch).i++;
        (*ch).k++;
    }
    (*ch).new_s[(*ch).k] = '\0';
}

void print_char_two(char *s, Value *ch)
{
    char *new_s;

    (*ch).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 + 1 + (*ch).width));
    while ((*ch).k < (*ch).i) {
        (*ch).new_s[(*ch).k] = s[(*ch).k];
        (*ch).k++;
    }
    (*ch).width = (*ch).width - 1;
    if ((*ch).flag != '-') {
        while ((*ch).width > 0) {
            (*ch).new_s[(*ch).k] = ' ';
            (*ch).k++;
            (*ch).width--;
        }
    }
}

char *print_char(char *s, ...)
{
    va_list list9;
    Value ch;

    va_start(list9, s);
    ch.i = va_arg(list9, int);
    ch.c = va_arg(list9, int);
    ch.flag = va_arg(list9, int);
    ch.width = va_arg(list9, int);
    va_end(list9);
    ch.k = 0;
    print_char_two(s, &ch);
    print_char_three(s, &ch);
    free(s);
    return (ch.new_s);
}
