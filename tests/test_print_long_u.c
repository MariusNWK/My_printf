/*
** EPITECH PROJECT, 2020
** test
** File description:
** print_long_u
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(print_long_u, copy_string_long_u_and_cie)
{
    char *str = print_long_u(my_strdup("%o"), 0, 350000, 10, '#', 15);

    cr_assert_str_eq(str, "     0000350000");
}
