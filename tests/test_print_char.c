/*
** EPITECH PROJECT, 2020
** test
** File description:
** print_char
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(print_char, print_a_char)
{
    char *res = print_char(my_strdup("ceci : %c est un F"), 7, 'F', '-', 5);

    cr_assert_str_eq(res, "ceci : F     est un F");
}
