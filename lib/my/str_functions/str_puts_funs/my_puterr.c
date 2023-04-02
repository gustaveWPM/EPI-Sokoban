/*
** EPITECH PROJECT, 2021
** my_puterr.c
** File description:
** Puts an error
*/

#include "my_lib.h"

void my_puterr(char *str)
{
    if (str == NULL)
        return;
    write(2, str, my_strlen(str));
}

void my_putstr(char *str)
{
    if (str == NULL)
        return;
    write(1, str, my_strlen(str));
}