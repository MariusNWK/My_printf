/*
** EPITECH PROJECT, 2020
** test
** File description:
** print_char_nbr
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(print_char_nbr, copy_string_nbr)
{
    char *str = print_char_nbr(my_strdup("c'est %b"),
        6, my_strdup("01010101"), 10, '-', 15);

    cr_assert_str_eq(str, "c'est 0001010101     ");
}
