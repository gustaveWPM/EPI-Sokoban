/*
** EPITECH PROJECT, 2021
** my_putchar_on_stderr.c
** File description:
** Puts a char on stderr
*/

#include "my_lib.h"

void my_putchar_on_stderr(char c)
{
    write(2, &c, 1);
}