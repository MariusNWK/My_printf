/*
** EPITECH PROJECT, 2020
** test
** File description:
** precision
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(precision, precision_finder)
{
    int n = precision("%.15d", 0);

    cr_assert_eq(n, 15);
}
