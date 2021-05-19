/*
** EPITECH PROJECT, 2020
** test
** File description:
** base_converter
*/
#include <criterion/criterion.h>
#include <stdio.h>

unsigned int base_converter(int, int);

Test(base_converter, pos_int_to_base_10)
{
    long long unsigned int n = base_converter(30, 10);
    cr_assert_eq(n, 30);
}

Test(base_converter, neg_int_to_base_10)
{
    long long unsigned int n = base_converter(2558, 8);
    cr_assert_eq(n, 4776);
}
