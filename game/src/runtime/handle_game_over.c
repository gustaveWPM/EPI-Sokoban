/*
** EPITECH PROJECT, 2021
** handle_game_over.c
** File description:
** Specific runtime handler : handles game over state
*/

#include "game_state_struct.h"
#include "runtime_tile_manager.h"
#include "runtime_char_neighbor.h"
#include "runtime_getters.h"

char try_box_move(game_state_t *game, int box_index, unsigned char dir)
{
    int neighbor_index;
    unsigned char opp_dir = get_opposite_dir(dir);

    neighbor_index = dir_char_neighbor_index(game, box_index, dir);
    if (tile_is_passable(game, neighbor_index)) {
        neighbor_index = dir_char_neighbor_index(game, box_index, opp_dir);
        if (tile_is_passable(game, neighbor_index))
            return (1);
    }
    return (0);
}

char box_is_stucked(game_state_t *game, int box_index)
{
    if (try_box_move(game, box_index, 2))
        return (0);
    if (try_box_move(game, box_index, 4))
        return (0);
    if (try_box_move(game, box_index, 6))
        return (0);
    if (try_box_move(game, box_index, 8))
        return (0);
    return (1);
}

void losing_boxes_counter(game_state_t *game, unsigned int i,
                            unsigned int *counter)
{
    map_infos_t *map_infos = game->map_infos;

    for (unsigned int j = 0; j < map_infos->boxes_amount; j++) {
        if (box_is_stucked(game, map_infos->boxes_index[i])) {
            *counter += 1;
            return;
        }
    }
}

void handle_game_over(game_state_t *game)
{
    unsigned int counter = 0;

    if (game->won == 1)
        return;
    for (unsigned int i = 0; i < game->map_infos->boxes_amount; i++)
        losing_boxes_counter(game, i, &counter);
    if (counter == game->map_infos->slots_amount) {
        game->won = -1;
        game->done = 1;
    }
}