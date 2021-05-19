/*
** EPITECH PROJECT, 2020
** base_converter
** File description:
** my_printf
*/
#include <stdio.h>
#include "my.h"

long long unsigned int base_converter(long long unsigned int n, int base)
{
    long long unsigned int b = 1;
    long long unsigned int power_ten = 1;
    long long unsigned int div = 0;
    long long unsigned int mod = n;
    long long unsigned int res = 0;

    if (n == base)
        return (10);
    while (b < n) {
        b = b * base;
        power_ten = power_ten * 10;
    }
    b = b / base;
    power_ten = power_ten / 10;
    while (mod != 0 && b != 0) { div = mod / b;
        mod = mod % b;
        res = div * power_ten + res;
        b = b / base;
        power_ten = power_ten / 10;
    }
    return (res);
}
