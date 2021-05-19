/*
** EPITECH PROJECT, 2020
** test
** File description:
** print_string
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(print_string, copy_string_and_cie)
{
    char *str = print_string(my_strdup("%s"), 0, "babyshark", '-', 15);

    cr_assert_str_eq(str, "babyshark      ");
}
