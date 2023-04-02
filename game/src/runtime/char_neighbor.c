/*
** EPITECH PROJECT, 2021
** char_neighbor.c
** File description:
** [Runtime] Returns a char's neighbor
*/

#include "game_state_struct.h"
#include "runtime_getters.h"
#include "str_verifications_funs.h"

int dir_char_neighbor_index(game_state_t *game, int index, unsigned char dir)
{
    unsigned int max_index = my_strlen(game->map_infos->map);
    unsigned char memo_dir = game->direction;

    if (game->direction == 0 || index == -1)
        return (-1);
    game->direction = dir;
    index += get_dir_delta(game);
    game->direction = memo_dir;
    if (index >= 0 && (unsigned int) index < max_index)
        return (index);
    return (-1);
}

int get_char_neighbor_index(game_state_t *game, int index)
{
    unsigned int max_index = my_strlen(game->map_infos->map);

    if (game->direction == 0 || index == -1)
        return (-1);
    index += get_dir_delta(game);
    if (index >= 0 && (unsigned int) index < max_index)
        return (index);
    return (-1);
}

char char_neighbor(game_state_t *game, int index)
{
    char neighbor = '#';
    unsigned int max_index = my_strlen(game->map_infos->map);

    if (game->direction == 0 || index == -1)
        return '#';
    index += get_dir_delta(game);
    if (index >= 0 && (unsigned int) index < max_index)
        neighbor = game->map_infos->map[index];
    if (neighbor == '\n' || neighbor == '\0')
        neighbor = '#';
    return (neighbor);
}