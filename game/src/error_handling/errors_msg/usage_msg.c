/*
** EPITECH PROJECT, 2021
** usage_msg.c
** File description:
** Bin usage msg
*/

#include "vocab.h"
#include "str_puts_funs.h"

void usage_msg(unsigned char is_error)
{
    if (is_error) {
        my_puterr(USAGE_MSG);
        return;
    }
    my_putstr(USAGE_MSG);
}