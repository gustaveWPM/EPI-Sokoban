/*
** EPITECH PROJECT, 2021
** char_movements_manager.c
** File description:
** [Runtime] Char movement manager
*/

#include "game_state_struct.h"
#include "runtime_tile_manager.h"
#include "runtime_char_neighbor.h"
#include "runtime_getters.h"
#include "str_verifications_funs.h"

unsigned char tile_is_passable(game_state_t *game, int index)
{
    char tile;
    int max_index = my_strlen(game->map_infos->map);

    if (index < 0 || index > max_index)
        return (0);
    tile = game->map_infos->map[index];
    if (is_wall(game, tile) || is_box(game, tile))
        return (0);
    if (tile == '\n' || tile == '\0')
        return (0);
    return (1);
}

int get_dir_delta(game_state_t *game)
{
    unsigned int one_line_delta = game->map_infos->width + 2;

    if (game->direction == 0)
        return (0);
    if (game->direction == 2)
        return (one_line_delta);
    if (game->direction == 8)
        return (one_line_delta * -1);
    if (game->direction == 4)
        return (-1);
    if (game->direction == 6)
        return (1);
    return (0);
}

void update_box_infos(game_state_t *game, int index)
{
    unsigned int max_index = game->map_infos->boxes_amount;
    int new_index = 0;

    for (unsigned int i = 0; i < max_index; i++) {
        if (game->map_infos->boxes_index[i] == (unsigned int) index) {
            new_index = get_char_neighbor_index(game, index);
            game->map_infos->boxes_index[i] = new_index;
            return;
        }
    }
}

unsigned int process_move(game_state_t *game, int index, char symbol)
{
    int memo_index = index;
    char ground_symbol = game->map_symbols->ground_symbol;

    if (is_box(game, symbol)) {
        if (!tile_is_passable(game, get_char_neighbor_index(game, index)))
            return (0);
        update_box_infos(game, index);
    }
    index += get_dir_delta(game);
    game->map_infos->map[memo_index] = game->map_infos->memo_map[memo_index];
    if (game->map_infos->map[memo_index] == symbol) {
        game->map_infos->map[memo_index] = ground_symbol;
        game->map_infos->memo_map[memo_index] = ground_symbol;
    }
    game->map_infos->map[index] = symbol;
    return (1);
}

void handle_move(game_state_t *game, int index)
{
    char box_sym = game->map_symbols->box_symbol;
    char player_sym = game->map_symbols->player_symbol;
    char neighbor;

    if (game->direction == 0 || index == -1)
        return;
    neighbor = char_neighbor(game, index);
    if (is_wall(game, neighbor))
        return;
    if (is_ground(game, neighbor) || is_slot(game, neighbor))
        process_move(game, index, player_sym);
    if (is_box(game, neighbor)) {
        if (process_move(game, get_char_neighbor_index(game, index), box_sym))
            process_move(game, index, player_sym);
    }
}