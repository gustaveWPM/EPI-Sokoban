/*
** EPITECH PROJECT, 2021
** unable_to_open_file_msg.c
** File description:
** Unable to open file msg
*/

#include "vocab.h"
#include "str_puts_funs.h"

void unable_to_open_file_msg(char **argv)
{
    my_puterr(UNABLE_TO_OPEN_FILE_MSG);
    my_puterr(argv[1]);
    my_puterr("\n");
}