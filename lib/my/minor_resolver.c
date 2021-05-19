/*
** EPITECH PROJECT, 2020
** minor_resolver
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void minor_resolver_long(Ulong *lu)
{
    while ((*lu).widthbis > 0) {
        if ((*lu).flag == '0')
            (*lu).new_s[(*lu).k] = '0';
        else
            (*lu).new_s[(*lu).k] = ' ';
        (*lu).k++;
        (*lu).widthbis--;
    }
}

void minor_resolver_hexa(Ulong *ph)
{
    while ((*ph).widthbis > 0) {
        if ((*ph).flag == '0')
            (*ph).new_s[(*ph).k] = '0';
        else
            (*ph).new_s[(*ph).k] = ' ';
        (*ph).k++;
        (*ph).widthbis--;
    }
}

void minor_resolver_int(Value *in)
{
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
