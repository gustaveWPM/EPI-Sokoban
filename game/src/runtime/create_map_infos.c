/*
** EPITECH PROJECT, 2021
** create_map_infos.c
** File description:
** Creates map infos Datas
*/

#include "game_state_struct.h"
#include "runtime_getters.h"
#include "runtime_initializers.h"
#include "runtime_terminate.h"
#include "runtime_tile_manager.h"
#include "str_verifications_funs.h"
#include <stdlib.h>
#include <errno.h>

void setup_map_infos(game_state_t *game)
{
    unsigned int map_str_len = my_strlen(game->map_infos->memo_map);
    char token;
    unsigned int cur_slot_index = 0;
    unsigned int cur_box_index = 0;

    initialize_map_infos_indexes_values(game);
    for (unsigned int i = 0; i < map_str_len; i++) {
        token = game->map_infos->memo_map[i];
        if (is_slot(game, token)) {
            game->map_infos->slots_index[cur_slot_index] = i;
            cur_slot_index += 1;
        }
        if (is_box(game, token)) {
            game->map_infos->memo_boxes_index[cur_box_index] = i;
            game->map_infos->boxes_index[cur_box_index] = i;
            cur_box_index += 1;
        }
        if (is_player(game, token))
            game->map_infos->memo_player_index = i;
    }
}

void create_map_infos(game_state_t *game, char *map_path)
{
    unsigned int map_str_len;
    char token;

    game->map_infos->map = get_map_str(map_path);
    game->map_infos->memo_map = get_map_str(map_path);
    if (game->map_infos->map == NULL
        || game->map_infos->memo_map == NULL)
        crash(game, ENOMEM);
    game->map_infos->width = get_map_width(game->map_infos->map);
    map_str_len = my_strlen(game->map_infos->memo_map);
    for (unsigned int i = 0; i < map_str_len; i++) {
        token = game->map_infos->memo_map[i];
        if (is_slot(game, token))
            game->map_infos->slots_amount += 1;
        if (is_box(game, token))
            game->map_infos->boxes_amount += 1;
        if (token == '\n')
            game->map_infos->height += 1;
    }
    setup_map_infos(game);
}