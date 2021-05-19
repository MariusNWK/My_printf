/*
** EPITECH PROJECT, 2020
** print_string
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void print_string_two(char *s, Value *st)
{
    if ((*st).flag == '-') {
        while ((*st).width > 0) {
            (*st).new_s[(*st).k] = ' ';
            (*st).k++;
            (*st).width--;
        }
    }
    while (s[(*st).i + 2] != '\0') {
        (*st).new_s[(*st).k] = s[(*st).i + 2];
        (*st).i++;
        (*st).k++;
    }
    (*st).new_s[(*st).k] = '\0';
}

void print_string_one(char *s, Value *st)
{
    (*st).k = 0;
    (*st).width = (*st).width - my_strlen((*st).str);
    if ((*st).width < 0)
        (*st).width = 0;
    (*st).new_s = malloc(sizeof(char) *
        (my_strlen(s) + 1 - 2 +
        my_strlen((*st).str) + (*st).width));
    while ((*st).k < (*st).i) {
        (*st).new_s[(*st).k] = s[(*st).k];
        (*st).k++;
    }
    if ((*st).flag != '-') {
        while ((*st).width > 0) {
            (*st).new_s[(*st).k] = ' ';
            (*st).k++;
            (*st).width--;
        }
    }
    for (int p = 0; (*st).str[p] != '\0'; p++, (*st).k++)
        (*st).new_s[(*st).k] = (*st).str[p];
}

char *print_string(char *s, ...)
{
    va_list list8;
    Value st;

    va_start(list8, s);
    st.i = va_arg(list8, int);
    st.str = va_arg(list8, char *);
    st.flag = va_arg(list8, int);
    st.width = va_arg(list8, int);
    va_end(list8);
    print_string_one(s, &st);
    print_string_two(s, &st);
    free(s);
    return (st.new_s);
}
