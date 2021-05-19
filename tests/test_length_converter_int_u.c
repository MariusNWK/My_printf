/*
** EPITECH PROJECT, 2020
** test
** File description:
** length_converter_int_u
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(length_converter_int_u, convert_types)
{
    long long unsigned int i = 3000000000000;
    unsigned short p = i;
    long long unsigned int n = length_converter_int_u(3000000000000, 'h');

    cr_assert_eq(n, p);
}
