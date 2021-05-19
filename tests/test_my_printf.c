/*
** EPITECH PROJECT, 2020
** test
** File description:
** my_printf
*/
#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

Test(my_printf, print_everything)
{
    cr_assert_str_eq(my_printf("le nombre est %d\n", 49), "le nombre est 49\n");
}
Test(my_printf, print_everything2)
{
    cr_assert_str_eq(my_printf("la lettre est %c\n", 'K'), "la lettre est K\n");
}
Test(my_printf, print_everything3)
{
    cr_assert_str_eq(my_printf("la phrase est %s\n",
        "manger des fruits"), "la phrase est manger des fruits\n");
}
Test(my_printf, print_everything4)
{
    cr_assert_str_eq(my_printf("le nombre est %+10.5d\n", 49),
        "le nombre est     +00049\n");
}
Test(my_printf, print_everything5)
{
    cr_assert_str_eq(my_printf("le nombre est %u\n", -55),
        "le nombre est 4294967241\n");
}
Test(my_printf, print_everything6)
{
    cr_assert_str_eq(my_printf("le nombre est %o\n", -55),
        "le nombre est 37777777711\n");
}
Test(my_printf, print_everything7)
{
    cr_assert_str_eq(my_printf("le nombre est %x\n", -55),
        "le nombre est ffffffc9\n");
}
Test(my_printf, print_everything8)
{
    cr_assert_str_eq(my_printf("le nombre est %X\n", -55),
        "le nombre est FFFFFFC9\n");
}
Test(my_printf, print_everything9)
{
    cr_assert_str_eq(my_printf("le nombre est %p\n", -55),
        "le nombre est 0xffffffc9\n");
}
Test(my_printf, print_everything10)
{
    cr_assert_str_eq(my_printf("le nombre est %-20.15o\n", -55),
        "le nombre est 000037777777711     \n");
}
Test(my_printf, print_everything11)
{
    cr_assert_str_eq(my_printf("le nombre est %-20.15b\n", 55),
        "le nombre est 000000000110111     \n");
}
Test(my_printf, print_everything12)
{
    char str[] = "cerise sur le gateau";
    str[10] = 20;
    str[19] = 130;

    cr_assert_str_eq(my_printf("la phrase est %S\n", str),
        "la phrase est cerise sur\\024le gatea\\202\n");
}
Test(my_printf, print_everything13)
{
    cr_assert_str_eq(my_printf("la phrase est %m\n"),
        "la phrase est Success\n");
}
Test(my_printf, print_everything14)
{
    cr_assert_str_eq(my_printf("%-10.15d %+s %#.10o %010u %020.18p\n", 500, "cerise", -500, -1000, 987789), "000000000000500 cerise 037777777014 4294966296 0x0000000000000f128d\n");
}
Test(my_printf, print_everything15)
{
    char str[] = "toto";
    str[1] = 6;

    cr_assert_str_eq(my_printf("le mot est %S\n", str),
        "le mot est t\\006to\n");
}
Test(my_printf, print_everything16)
{
    cr_assert_str_eq(my_printf("le nombre est % d\nle nombre est % d\n", 500, -500),
        "le nombre est  500\nle nombre est -500\n");
}
Test(my_printf, print_everything17)
{
    cr_assert_str_eq(my_printf("le nombre est % d  le nombre est % d  le nombre est %d\n", 500, -500, 3000000000),
        "le nombre est  500  le nombre est -500  le nombre est -1294967296\n");
}
Test(my_printf, print_everything18)
{
    cr_assert_str_eq(my_printf("le nombre est %015d\n", 5697),
        "le nombre est 000000000005697\n");
}
Test(my_printf, print_everything19)
{
    cr_assert_str_eq(my_printf("le nombre est %d %d %d\n", 5697, 0, 2147483647),
        "le nombre est 5697 0 2147483647\n");
}
Test(my_printf, print_everything20)
{
    cr_assert_str_eq(my_printf("le nombre est %d %d %d\n", 5697, -0, 2147483647),
        "le nombre est 5697 0 2147483647\n");
}
Test(my_printf, print_everything21)
{
    cr_assert_str_eq(my_printf("le nombre est %x\n", 0),
        "le nombre est 0\n");
}
Test(my_printf, print_everything22)
{
    cr_assert_str_eq(my_printf("le nombre est %o\n", 0),
        "le nombre est 0\n");
}
Test(my_printf, print_everything23)
{
    cr_assert_str_eq(my_printf("le nombre est %u\n", 0),
        "le nombre est 0\n");
}
Test(my_printf, print_everything24)
{
    cr_assert_str_eq(my_printf("le nombre est %llX\n", 0),
        "le nombre est 0\n");
}
Test(my_printf, print_everything25)
{
    cr_assert_str_eq(my_printf("le nombre est %-15.10p suite\n", 8766),
        "le nombre est 0x000000223e    suite\n");
}
Test(my_printf, print_everything26)
{
    cr_assert_str_eq(my_printf("%d %s le nombre est %-15.10p suite %d %s\n", 10, "cerise", 8766, 10, "cerise"),
        "10 cerise le nombre est 0x000000223e    suite 10 cerise\n");
}
