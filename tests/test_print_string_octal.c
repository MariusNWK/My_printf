/*
** EPITECH PROJECT, 2020
** test
** File description:
** print_string_octal
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(print_string_octal, copy_string_but_unprintable_become_octal)
{
    char mp[] = "HelloWorld";
    mp[2] = 6;
    mp[6] = 130;
    char *str = print_string_octal(my_strdup("c'est %S"), 6, mp, '-', 20);

    cr_assert_str_eq(str, "c'est He\\006loW\\202rld    ");
}
