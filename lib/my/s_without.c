/*
** EPITECH PROJECT, 2020
** s_without
** File description:
** my_printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

char *s_without_between2(char *s, int i)
{
    int j = 0;
    int k = 0;
    char *new_s;

    for (j = i + 1; s[j] == 'h' || s[j] == 'l' || s[j] == 'q'; j++);
    new_s = malloc(sizeof(char) * (my_strlen(s) - (j - i - 1) + 1));
    for (k = 0; k <= i || k == 0; k++)
        new_s[k] = s[k];
    for (; s[j] != '\0'; j++, k++)
        new_s[k] = s[j];
    new_s[k] = '\0';
    free(s);
    return (new_s);
}

char *s_without_between(char *s, int i)
{
    int j = 0;
    int k = 0;
    char *new_s;

    for (j = i + 1; (s[j] < 'a' || s[j] > 'z') &&
        (s[j] < 'A' || s[j] > 'Z') && (s[j] != '%'); j++);
    new_s = malloc(sizeof(char) * (my_strlen(s) - (j - i - 1) + 1));
    for (k = 0; k <= i || k == 0; k++)
        new_s[k] = s[k];
    for (; s[j] != '\0'; j++, k++)
        new_s[k] = s[j];
    new_s[k] = '\0';
    free(s);
    return (new_s);
}

char *s_without_flag(char *s, int i)
{
    int j = 0;
    int k = 0;
    char *new_s;

    for (j = i + 1; s[j] == '#' || s[j] == '0' || s[j] == '-' ||
        s[j] == ' ' || s[j] == '+'; j++);
    new_s = malloc(sizeof(char) * (my_strlen(s) - (j - i - 1) + 1));
    for (k = 0; k <= i || k == 0; k++)
        new_s[k] = s[k];
    for (; s[j] != '\0'; j++, k++)
        new_s[k] = s[j];
    new_s[k] = '\0';
    free(s);
    return (new_s);
}

char *s_without_width(char *s, int i)
{
    int j = 0;
    int k = 0;
    char *new_s;

    for (j = i + 1; s[j] >= '0' && s[j] <= '9'; j++);
    new_s = malloc(sizeof(char) * (my_strlen(s) - (j - i - 1) + 1));
    for (k = 0; k <= i || k == 0; k++)
        new_s[k] = s[k];
    for (; s[j] != '\0'; j++, k++)
        new_s[k] = s[j];
    new_s[k] = '\0';
    free(s);
    return (new_s);
}
