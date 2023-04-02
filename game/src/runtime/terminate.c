/*
** EPITECH PROJECT, 2021
** terminate.c
** File description:
** Terminates the runtime
*/

#include "game_state_struct.h"
#include "dependencies.h"
#include "vocab.h"
#include "errors_msg.h"
#include "str_puts_funs.h"
#include <errno.h>

void terminate_ncurses(game_state_t *game)
{
    game->running_ncurses = 0;
    clear();
    attroff(COLOR_PAIR(3));
    endwin();
}

void clear_game_state(game_state_t *game)
{
    if (game->map_infos) {
        if (game->map_infos->map)
            free(game->map_infos->map);
        if (game->map_infos->memo_map)
            free(game->map_infos->memo_map);
        if (game->map_infos->memo_boxes_index)
            free(game->map_infos->memo_boxes_index);
        if (game->map_infos->boxes_index)
            free(game->map_infos->boxes_index);
        if (game->map_infos->slots_index)
            free(game->map_infos->slots_index);
    if (game->map_infos)
        free(game->map_infos);
    if (game->map_symbols)
        free(game->map_symbols);
    }
}

void terminate(game_state_t *game)
{
    char exit_code = 0;

    if (game) {
        if (game->running_ncurses)
            terminate_ncurses(game);
    } else {
        return;
    }
    if (game->won == -1) {
        exit_code = 1;
    }
    clear_game_state(game);
    if (exit_code)
        exit(exit_code);
}

void crash(game_state_t *game, int error_code)
{
    terminate(game);
    if (error_code == ENOMEM)
        failed_to_malloc_msg();
    exit(error_code);
}