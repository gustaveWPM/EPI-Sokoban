/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** Returns the str len
*/

#include "my_lib.h"

int my_strlen(char *str)
{
    int len = 0;

    if (str == NULL)
        return (0);
    for (len = 0; str[len]; len++);
    return (len);
}