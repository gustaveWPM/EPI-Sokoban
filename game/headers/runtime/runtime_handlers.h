/*
** EPITECH PROJECT, 2021
** runtime_handlers.h
** File description:
** Runtime Handlers
*/

#ifndef RUNTIME_HANDLERS_H
#define RUNTIME_HANDLERS_H
#include "game_state_struct.h"
char handle_input(game_state_t *game);
void process_pause(game_state_t *game);
void process_events(game_state_t *game);
void handle_move(game_state_t *game, int index);
void handle_win(game_state_t *game);
void handle_game_over(game_state_t *game);
unsigned int process_move(game_state_t *game, int index, char symbol);
#endif