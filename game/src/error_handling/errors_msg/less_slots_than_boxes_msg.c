/*
** EPITECH PROJECT, 2021
** less_slots_than_boxes_msg.c
** File description:
** Less slots than boxes msg
*/

#include "vocab.h"
#include "str_puts_funs.h"

void less_slots_than_boxes_msg(char already_invalid_map_infos)
{
    if (already_invalid_map_infos)
        my_puterr(MAP_INFOS_ERRORS_SEPARATOR);
    my_puterr(LESS_SLOTS_THAN_BOXES_MSG);
}