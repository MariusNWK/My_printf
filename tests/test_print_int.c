/*
** EPITECH PROJECT, 2020
** test
** File description:
** print_int
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(print_int, copy_percent_d_and_cie)
{
    char *str = print_int(my_strdup("%d"), 0, 695, 5, 0, '+', 10);

    cr_assert_str_eq(str, "    +00695");
}
