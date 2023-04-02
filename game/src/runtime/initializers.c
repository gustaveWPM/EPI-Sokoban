/*
** EPITECH PROJECT, 2021
** initializers.c
** File description:
** Runtime initializers/setup
*/

#include "game_state_struct.h"
#include "map_infos_struct.h"
#include "map_symbols_struct.h"
#include "runtime_terminate.h"
#include "constants.h"
#include <ncurses.h>
#include <stdlib.h>
#include <errno.h>

void initialize_map_infos_indexes_values(game_state_t *game)
{
    unsigned int memsize = 0;

    memsize = sizeof(unsigned int) * game->map_infos->boxes_amount;
    game->map_infos->memo_boxes_index = malloc(memsize);
    game->map_infos->boxes_index = malloc(memsize);
    game->map_infos->slots_index = malloc(memsize);
    if (game->map_infos->memo_boxes_index == NULL
        || game->map_infos->boxes_index == NULL
        || game->map_infos->slots_index == NULL)
        crash(game, ENOMEM);
    for (unsigned int i = 0; i < game->map_infos->boxes_amount; i++) {
        game->map_infos->memo_boxes_index[i] = 0;
        game->map_infos->boxes_index[i] = 0;
        game->map_infos->slots_index[i] = 0;
    }
}

void initialize_map_symbols(game_state_t *game)
{
    game->map_symbols = malloc(sizeof(map_symbols_t));
    if (game->map_symbols == NULL)
        crash(game, ENOMEM);
    game->map_symbols->box_symbol = BOX_SYMBOL;
    game->map_symbols->wall_symbol = WALL_SYMBOL;
    game->map_symbols->ground_symbol = GROUND_SYMBOL;
    game->map_symbols->player_symbol = PLAYER_SYMBOL;
    game->map_symbols->slot_symbol = SLOT_SYMBOL;
}

void initialize_map_infos(game_state_t *game)
{
    game->map_infos = malloc(sizeof(map_infos_t));
    if (game->map_infos == NULL)
        crash(game, ENOMEM);
    game->map_infos->boxes_amount = 0;
    game->map_infos->slots_amount = 0;
    game->map_infos->height = 0;
    game->map_infos->width = 0;
    game->map_infos->map = NULL;
    game->map_infos->memo_map = NULL;
}

game_state_t initialize_game_state(game_state_t game)
{
    game.key_pressed = -1;
    game.done = 0;
    game.direction = 0;
    game.paused = 0;
    game.won = 0;
    game.term_cols = COLS;
    game.term_lines = LINES;
    game.running_ncurses = 0;
    initialize_map_infos(&game);
    initialize_map_symbols(&game);
    return (game);
}

void initialize_ncurses(game_state_t *game)
{
    initscr();
    curs_set(false);
    keypad(stdscr, true);
    game->running_ncurses = 1;
    if (has_colors() == FALSE)
        return;
    start_color();
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(3));
}