/*
** EPITECH PROJECT, 2021
** missing_starting_position_msg.c
** File description:
** Missing starting position msg
*/

#include "vocab.h"
#include "str_puts_funs.h"

void missing_starting_position_msg(char already_invalid_map_infos)
{
    if (already_invalid_map_infos)
        my_puterr(MAP_INFOS_ERRORS_SEPARATOR);
    my_puterr(MISSING_STARTING_POSITION_MSG);
}