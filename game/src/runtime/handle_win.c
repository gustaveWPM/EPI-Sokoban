/*
** EPITECH PROJECT, 2021
** handle_win.c
** File description:
** Specific runtime handler : handles win state
*/

#include "game_state_struct.h"
#include "map_infos_struct.h"

void winning_boxes_counter(game_state_t *game, unsigned int i,
                            unsigned int *counter)
{
    map_infos_t *map_infos = game->map_infos;

    for (unsigned int j = 0; j < map_infos->boxes_amount; j++) {
        if (map_infos->slots_index[j] == map_infos->boxes_index[i]) {
            *counter += 1;
            return;
        }
    }
}

void handle_win(game_state_t *game)
{
    unsigned int counter = 0;

    for (unsigned int i = 0; i < game->map_infos->boxes_amount; i++)
        winning_boxes_counter(game, i, &counter);
    if (counter == game->map_infos->slots_amount) {
        game->won = 1;
        game->done = 1;
    }
}