/*
** EPITECH PROJECT, 2021
** invalid_char_msg.c
** File description:
** Invalid char msg
*/

#include "vocab.h"
#include "str_puts_funs.h"

void invalid_char_msg(char token)
{
    my_puterr(INVALID_CHAR_MSG);
    my_putchar_on_stderr(token);
    my_putchar_on_stderr('\n');
}