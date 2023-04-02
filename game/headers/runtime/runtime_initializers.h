/*
** EPITECH PROJECT, 2021
** runtime_initializers.h
** File description:
** Runtime initializers
*/

#ifndef RUNTIME_INITIALIZERS_H
#define RUNTIME_INITIALIZERS_H
#include "game_state_struct.h"
game_state_t initialize_game_state(game_state_t game);
void initialize_map_infos_indexes_values(game_state_t *game);
void initialize_ncurses(game_state_t *game);
#endif