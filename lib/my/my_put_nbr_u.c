/*
** EPITECH PROJECT, 2020
** my_put_nbr_u
** File description:
** my_printf
*/

#include "my.h"
#include <unistd.h>

int my_put_nbr_u(unsigned int nb)
{
    int i = 0;

    if (nb == -2147483648) {
        write(1, "-2147483648", 12);
        return (0);
    }
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    i = nb % 10 + 48;
    my_putchar(i);
    return (0);
}
