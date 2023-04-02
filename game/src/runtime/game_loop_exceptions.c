/*
** EPITECH PROJECT, 2021
** game_loop_exceptions.c
** File description:
** [Runtime] Game loop exceptions
*/

#include "game_state_struct.h"
#include "runtime_terminate.h"
#include "dyn_str_funs.h"
#include <stdlib.h>
#include <ncurses.h>
#include <errno.h>

char too_small_window(game_state_t *game)
{
    int map_width = game->map_infos->width;
    int map_height = game->map_infos->height;

    if (COLS < map_width || LINES < map_height)
        return (1);
    return (0);
}

void recover_initial_map_datas(game_state_t *game)
{
    unsigned int player_index = game->map_infos->memo_player_index;
    char player_symbol = game->map_symbols->player_symbol;
    char box_symbol = game->map_symbols->box_symbol;
    unsigned int cur_index = 0;

    for (unsigned int i = 0; i < game->map_infos->boxes_amount; i++) {
        cur_index = game->map_infos->memo_boxes_index[i];
        game->map_infos->boxes_index[i] = game->map_infos->memo_boxes_index[i];
        game->map_infos->memo_map[cur_index] = box_symbol;
    }
    game->map_infos->memo_map[player_index] = player_symbol;
}

void reset_map(game_state_t *game)
{
    recover_initial_map_datas(game);
    (game->map_infos->map) ? free(game->map_infos->map) : NULL;
    game->map_infos->map = my_strdup(game->map_infos->memo_map);
    if (game->map_infos->map == NULL)
        crash(game, ENOMEM);
    game->direction = 0;
    game->done = 0;
    game->key_pressed = -1;
    game->won = 0;
}

void soft_game_cancel(game_state_t *game)
{
    game->done = 1;
    game->direction = 0;
}