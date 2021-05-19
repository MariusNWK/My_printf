/*
** EPITECH PROJECT, 2020
** test
** File description:
** print_decimal
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(print_decimal, copy_decimal_nbr)
{
    char *str = print_decimal(my_strdup("c'est %u"),
                            6, -2508, 12, 0, '-', 15);

    cr_assert_str_eq(str, "c'est 004294964788   ");
}
