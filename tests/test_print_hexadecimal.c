/*
** EPITECH PROJECT, 2020
** test
** File description:
** print_hexadecimal
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(print_hexadecimal, copy_decimal_nbr)
{
    char *str = print_hexadecimal(my_strdup("c'est %x"),
        6, -2508, 12, 0, '-', 15);

    cr_assert_str_eq(str, "c'est 0000fffff634   ");
}
