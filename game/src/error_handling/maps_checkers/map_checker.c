/*
** EPITECH PROJECT, 2021
** map_checker.c
** File description:
** Map checker
*/

#include "vocab.h"
#include "str_verifications_funs.h"
#include "str_puts_funs.h"
#include "err_handling_funs.h"
#include "constants.h"
#include <stdlib.h>

char invalid_map_infos(unsigned int slots,
                            unsigned int boxes, unsigned int start_points)
{
    char is_invalid = 0;
    if (slots > boxes) {
        more_slots_than_boxes_msg(is_invalid);
        is_invalid = 1;
    }
    if (slots < boxes) {
        less_slots_than_boxes_msg(is_invalid);
        is_invalid = 1;
    }
    if (start_points == 0) {
        missing_starting_position_msg(is_invalid);
        is_invalid = 1;
    }
    if (start_points > 1) {
        too_much_starting_positions_msg(is_invalid);
        is_invalid = 1;
    }
    if (is_invalid)
        my_puterr(MAP_INFOS_ERRORS_SEPARATOR);
    return (is_invalid);
}

void update_tokens_counters(char token, unsigned int *slots,
                            unsigned int *boxes, unsigned int *start_p)
{
    if (token == SLOT_SYMBOL)
        *slots += 1;
    if (token == BOX_SYMBOL)
        *boxes += 1;
    if (token == PLAYER_SYMBOL)
        *start_p += 1;
}

char invalid_map_width(char *map_str)
{
    unsigned int map_str_len = my_strlen(map_str);
    unsigned int cur_width = 0;
    unsigned int width = 0;

    for (unsigned int i = 0; i < map_str_len; i++) {
        if ((map_str[i] == '\n' || map_str[i] == '\0')
            && width != 0 && cur_width != width) {
            my_puterr(INVALID_MAP_WIDTH_MSG);
            return (1);
        }
        if (map_str[i] == '\n' || map_str[i] == '\0')
            cur_width = -1;
        else
            cur_width += 1;
        if ((map_str[i] == '\n' || map_str[i] == '\0') && width == 0)
            width = i - 1;
    }
    return (0);
}

char invalid_token(char *map_str, unsigned int *slots,
                        unsigned int *boxes, unsigned int *start_points)
{
    unsigned int map_str_len = my_strlen(map_str);

    for (unsigned int i = 0; i < map_str_len; i++) {
        if (!char_is_in_char_collection(map_str[i], " XPO#\n")) {
            invalid_char_msg(map_str[i]);
            return (1);
        }
        update_tokens_counters(map_str[i], slots, boxes, start_points);
    }
    return (0);
}

char invalid_map_file(char *map_str)
{
    unsigned int map_str_len = my_strlen(map_str);
    unsigned int slots = 0;
    unsigned int boxes = 0;
    unsigned int start_points = 0;
    unsigned char is_invalid = 0;

    if (map_str_len == 0)
        return (0);
    if (invalid_token(map_str, &slots, &boxes, &start_points))
        is_invalid = 1;
    if (invalid_map_width(map_str))
        is_invalid = 1;
    if (invalid_map_infos(slots, boxes, start_points))
        is_invalid = 1;
    (map_str) ? free(map_str) : NULL;
    map_str = NULL;
    if (is_invalid)
        return (1);
    return (0);
}