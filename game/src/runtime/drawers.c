/*
** EPITECH PROJECT, 2021
** drawers.c
** File description:
** Runtime drawers
*/

#include "game_state_struct.h"
#include "str_verifications_funs.h"
#include "dyn_str_funs.h"
#include "str_counting_funs.h"
#include "runtime_terminate.h"
#include "vocab.h"
#include <ncurses.h>
#include <stdlib.h>
#include <errno.h>

int compute_centerx_offset(int width)
{
    int x_offset = COLS / 2;

    if (width > 1)
        x_offset -= width / 2;
    return (x_offset);
}

int compute_centery_offset(int height)
{
    int y_offset = LINES / 2;

    if (height > 1)
        y_offset -= height / 2;
    return (y_offset);
}

void draw_resize_term_msg(game_state_t *game)
{
    char *msg = RESIZE_TERM_MSG;
    int width = my_strlen(msg);
    int height = str_count_char(msg, '\n');
    int x_offset = compute_centerx_offset(width);
    int y_offset = compute_centery_offset(height);

    if (game->term_cols != COLS || game->term_lines != LINES) {
        clear();
        mvprintw(y_offset, x_offset, msg);
        refresh();
        game->term_cols = COLS;
        game->term_lines = LINES;
    } else {
        mvprintw(y_offset, x_offset, msg);
    }
}

void draw_map(game_state_t *game)
{
    int width = game->map_infos->width + 2;
    int height = game->map_infos->height;
    int x_offset = compute_centerx_offset(width);
    int y_offset = compute_centery_offset(height);
    char *buffer = my_strdup(game->map_infos->map);

    if (buffer == NULL)
        crash(game, ENOMEM);
    for (int y = 0; y <= height; y++)
        mvprintw(y_offset + y, x_offset, "%.*s\n", width, (buffer + y * width));
    free(buffer);
}