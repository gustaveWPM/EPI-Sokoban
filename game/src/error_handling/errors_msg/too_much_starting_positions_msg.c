/*
** EPITECH PROJECT, 2021
** too_much_starting_positions_msg.c
** File description:
** Too much starting positions msg
*/

#include "vocab.h"
#include "str_puts_funs.h"

void too_much_starting_positions_msg(char already_invalid_map_infos)
{
    if (already_invalid_map_infos)
        my_puterr(MAP_INFOS_ERRORS_SEPARATOR);
    my_puterr(TOO_MUCH_STARTING_POSITIONS_MSG);
}