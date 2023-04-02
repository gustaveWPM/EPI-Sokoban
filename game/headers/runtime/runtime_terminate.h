/*
** EPITECH PROJECT, 2021
** runtime_terminate.h
** File description:
** Runtime Terminate functions
*/

#ifndef RUNTIME_TERMINATE_H
#define RUNTIME_TERMINATE_H
#include "game_state_struct.h"
void terminate(game_state_t *game);
void terminate_ncurses(game_state_t *game);
void crash(game_state_t *game, int error_code);
#endif