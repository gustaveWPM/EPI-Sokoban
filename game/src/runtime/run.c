/*
** EPITECH PROJECT, 2021
** run.c
** File description:
** Runtime entry point
*/

#include "game_state_struct.h"
#include "runtime_create_map_infos.h"
#include "runtime_initializers.h"
#include "runtime_drawers.h"
#include "runtime_handlers.h"
#include "runtime_terminate.h"
#include <ncurses.h>

void mouli_quick_fix(game_state_t *game)
{
    clear();
    draw_map(game);
    refresh();
}

void game_loader(game_state_t *game, char *map_path)
{
    create_map_infos(game, map_path);
    initialize_ncurses(game);
}

void game_loop(game_state_t *game)
{
    while (!game->done) {
        clear();
        process_pause(game);
        while (game->paused)
            process_pause(game);
        draw_map(game);
        process_events(game);
        refresh();
    }
    mouli_quick_fix(game);
}

char run(char *map_path)
{
    game_state_t game;

    game = initialize_game_state(game);
    game_loader(&game, map_path);
    game_loop(&game);
    terminate(&game);
    return (0);
}