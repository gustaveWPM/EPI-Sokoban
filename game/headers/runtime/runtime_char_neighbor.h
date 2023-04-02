/*
** EPITECH PROJECT, 2021
** runtime_char_neighbor.h
** File description:
** Runtime char neighbor
*/

#ifndef RUNTIME_CHAR_NEIGHBOR_H
#define RUNTIME_CHAR_NEIGHBOR_H
#include "game_state_struct.h"
char char_neighbor(game_state_t *game, int index);
int dir_char_neighbor_index(game_state_t *game, int index, unsigned char dir);
#endif