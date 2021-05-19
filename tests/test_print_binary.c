/*
** EPITECH PROJECT, 2020
** test
** File description:
** print_binary
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(print_binary, copy_string_nbr)
{
    char *str = print_binary(my_strdup("c'est %b"),
        6, 200, 10, '-', 15);

    cr_assert_str_eq(str, "c'est 0011001000     ");
}
