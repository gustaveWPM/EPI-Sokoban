/*
** EPITECH PROJECT, 2021
** runtime_game_loop_exceptions.h
** File description:
** Runtime game loop exceptions
*/

#ifndef RUNTIME_GAME_LOOP_EXCEPTIONS_H
#define RUNTIME_GAME_LOOP_EXCEPTIONS_H
#include "game_state_struct.h"
void reset_map(game_state_t *game);
void soft_game_cancel(game_state_t *game);
char too_small_window(game_state_t *game);
#endif