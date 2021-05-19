/*
** EPITECH PROJECT, 2020
** hexa_converter
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *hexa_converter_two
    (long long unsigned int n, long long unsigned int b,
    int size, long long unsigned int add)
{
    long long unsigned int res = 0;
    int i = 0;
    char *result;

    result = malloc(sizeof(char) * (size + 1));
    while (n != 0) {
        res = n / b;
        if (res <= 9)
            result[i] = res + 48;
        else
            result[i] = res + add;
        n = n % b;
        b = b / 16;
        i++;
    }
    result[i] = '\0';
    return (result);
}

char *hexa_converter(long long unsigned int n, char c)
{
    int i = 0;
    long long unsigned int b = 1;
    long long unsigned int add = 0;
    int size = 0;
    char *result;

    if (n == 0)
        return (my_strdup("0"));
    if (n == 16)
        return (my_strdup("10"));
    if (c == 'x')
        add = 87;
    else
        add = 55;
    while (b < n) {
        b = b * 16;
        size = size + 1;
    }
    b = b / 16;
    return (hexa_converter_two(n, b, size, add));
}
