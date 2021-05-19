/*
** EPITECH PROJECT, 2020
** test
** File description:
** print_octal
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(print_octal, copy_octal_nbr)
{
    char *str = print_octal(my_strdup("c'est %o"),
        6, 250890769, 12, 0, '-', 15);

    cr_assert_str_eq(str, "c'est 001675045021   ");
}
