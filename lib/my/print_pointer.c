/*
** EPITECH PROJECT, 2020
** print_pointer
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

void print_pointer_four(char *s, char flag, Ptr *pp)
{
    for (int j = 0; j < (*pp).size_nbr; j++, (*pp).n++)
        (*pp).new_s[(*pp).n] = (*pp).nbr[j];
    if (flag == '-') {
        while ((*pp).width > 0) {
            (*pp).new_s[(*pp).n] = ' ';
            (*pp).n++;
            (*pp).width--;
        }
    }
    for (; s[(*pp).itri + (*pp).size_nbr] != '\0';
        (*pp).itri++, (*pp).n++)
        (*pp).new_s[(*pp).n] = s[(*pp).itri + (*pp).size_nbr];
    (*pp).new_s[(*pp).n] = '\0';
}

void print_pointer_three(char *s, char flag, Ptr *pp)
{
    if ((*pp).width > my_strlen((*pp).nbr))
        (*pp).width = (*pp).width - my_strlen((*pp).nbr);
    else
        (*pp).width = 0;
    (*pp).new_s = malloc(sizeof(char) * (my_strlen(s) + 1 + (*pp).width));
    for (int j = 0; j < (*pp).itri; j++, (*pp).n++)
        (*pp).new_s[(*pp).n] = s[j];
    if (flag != '-') {
        while ((*pp).width > 0) {
            (*pp).new_s[(*pp).n] = ' ';
            (*pp).n++;
            (*pp).width--;
        }
    }
}

void print_pointer_two(char *s, int i, Ptr *pp)
{
    int k = 2;
    int ibis = i;

    for (; (s[i + 2] >= '0' && s[i + 2] <= '9') ||
        (s[i + 2] >= 'a' && s[i + 2] <= 'f'); i++)
        (*pp).size_nbr = (*pp).size_nbr + 1;
    (*pp).size_nbr = (*pp).size_nbr + 2;
    (*pp).nbr = malloc(sizeof(char) * ((*pp).size_nbr + 1));
    (*pp).nbr[0] = '0';
    (*pp).nbr[1] = 'x';
    for (; k < (*pp).size_nbr; k++, ibis++) {
        (*pp).nbr[k] = s[ibis + 2];
    }
    (*pp).nbr[k] = '\0';
}

char *print_pointer(char *s, ...)
{
    Ptr pp;
    va_list Lptr;
    int i = 0;
    char flag = 0;

    va_start(Lptr, s);
    i = va_arg(Lptr, int);
    flag = va_arg(Lptr, int);
    pp.width = va_arg(Lptr, int);
    pp.size_nbr = 0;
    pp.itri = i;
    pp.n = 0;
    print_pointer_two(s, i, &pp);
    print_pointer_three(s, flag, &pp);
    print_pointer_four(s, flag, &pp);
    free(s);
    free(pp.nbr);
    return (pp.new_s);
}
