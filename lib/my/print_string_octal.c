/*
** EPITECH PROJECT, 2020
** print_string_octal
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void print_string_octal_four(char *s, Value *po)
{
    if ((*po).flag == '-') {
        while ((*po).width > 0) {
            (*po).new_str[(*po).k] = ' ';
            (*po).k++;
            (*po).width--;
        }
    }
    (*po).new_str[(*po).k] = '\0';
    (*po).new_s = malloc(sizeof(char) *
        (my_strlen(s) - 2 + my_strlen((*po).new_str) + 1));
    for ((*po).p = 0; (*po).p < (*po).i; (*po).p++)
        (*po).new_s[(*po).p] = s[(*po).p];
    for (int j = 0; j < my_strlen((*po).new_str); j++, (*po).p++)
        (*po).new_s[(*po).p] = (*po).new_str[j];
    for (; s[(*po).i + 2] != '\0'; (*po).i++, (*po).p++)
        (*po).new_s[(*po).p] = s[(*po).i + 2];
    (*po).new_s[(*po).p] = '\0';
}

void print_string_octal_three(Value *po)
{
    for (int j = 0; (*po).str[j] != '\0'; j++) {
        if ((*po).str[j] < 32 || (*po).str[j] > 127) {
            (*po).ascii = (*po).str[j];
            if ((*po).ascii < 0)
                (*po).ascii = 127 + (*po).ascii + 127 + 2;
            (*po).ascii = base_converter((*po).ascii, 8);
            (*po).nbr = converter_percent_big_s((*po).ascii);
            (*po).new_str[(*po).k] = '\\';
            (*po).k = (*po).k + 1;
            for (int n = 0; n < my_strlen((*po).nbr); n++, (*po).k++)
                (*po).new_str[(*po).k] = (*po).nbr[n];
            free((*po).nbr);
        }
        else {
            (*po).new_str[(*po).k] = (*po).str[j];
            (*po).k++;
        }
    }
}

void print_string_octal_two(Value *po)
{
    (*po).new_str = malloc(sizeof(char) *
        ((*po).size_new_str + 1 + (*po).width));
    if ((*po).flag != '-') {
        while ((*po).width > 0) {
            (*po).new_str[(*po).k] = ' ';
            (*po).k++;
            (*po).width--;
        }
    }
}

void print_string_octal_one(Value *po)
{
    (*po).size_new_str = 0;
    (*po).ascii = 0;
    (*po).k = 0;
    (*po).p = 0;
    (*po).size_new_str = my_strlen((*po).str);
    for (int j = 0; (*po).str[j] != '\0'; j++) {
        if ((*po).str[j] < 32 || (*po).str[j] > 127) {
            (*po).ascii = (*po).str[j];
            if ((*po).ascii < 0)
                (*po).ascii = 127 + (*po).ascii + 127 + 2;
            (*po).ascii = base_converter((*po).ascii, 8);
            (*po).nbr = converter_percent_big_s((*po).ascii);
            (*po).size_new_str = (*po).size_new_str + my_strlen((*po).nbr);
            free((*po).nbr);
        }
    }
    (*po).width = (*po).width - (*po).size_new_str;
    if ((*po).width < 0)
        (*po).width = 0;
}

char *print_string_octal(char *s, ...)
{
    va_list list10;
    Value po;

    va_start(list10, s);
    po.i = va_arg(list10, int);
    po.str = va_arg(list10, char *);
    po.flag = va_arg(list10, int);
    po.width = va_arg(list10, int);
    va_end(list10);
    print_string_octal_one(&po);
    print_string_octal_two(&po);
    print_string_octal_three(&po);
    print_string_octal_four(s, &po);
    free(s);
    return (po.new_s);
}
