/*
** EPITECH PROJECT, 2021
** handlers.c
** File description:
** Runtime handlers
*/

#include "game_state_struct.h"
#include "runtime_handlers.h"
#include "runtime_drawers.h"
#include "runtime_getters.h"
#include "runtime_game_loop_exceptions.h"
#include <ncurses.h>

char handle_input(game_state_t *game)
{
    unsigned char dir = 0;

    game->key_pressed = getch();
    dir = get_key_dir(game->key_pressed);
    if (dir) {
        game->direction = dir;
        return (1);
    }
    if (game->key_pressed == KEY_BACKSPACE) {
        soft_game_cancel(game);
        return (0);
    }
    if (game->key_pressed == ' ') {
        reset_map(game);
        return (0);
    }
    return (0);
}

void process_pause(game_state_t *game)
{
    char window_is_too_small;

    window_is_too_small = too_small_window(game);
    if (window_is_too_small) {
        draw_resize_term_msg(game);
        game->paused = 1;
        refresh();
    } else {
        clear();
        refresh();
        game->paused = 0;
    }
}

void process_events(game_state_t *game)
{
    char input_triggered = handle_input(game);

    if (input_triggered) {
        handle_move(game, get_player_index(game));
        handle_win(game);
        handle_game_over(game);
    }
}
