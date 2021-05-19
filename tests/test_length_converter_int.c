/*
** EPITECH PROJECT, 2020
** test
** File description:
** length_converter_int
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(length_converter_int, send_to_converter_with_good_type)
{
    int n = 987560;
    short sh = n;
    char *str = length_converter_int(987560, 'h');
    char *res = int_to_str_converter(sh);

    cr_assert_str_eq(str, res);
}
