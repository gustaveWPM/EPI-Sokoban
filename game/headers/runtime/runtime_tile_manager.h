/*
** EPITECH PROJECT, 2021
** runtime_tile_manager.h
** File description:
** Runtime tile manager
*/

#ifndef RUNTIME_TILE_MANAGER_H
#define RUNTIME_TILE_MANAGER_H
#include "game_state_struct.h"
unsigned int is_slot(game_state_t *game, char tile);
unsigned int is_box(game_state_t *game, char tile);
unsigned int is_player(game_state_t *game, char tile);
unsigned int is_ground(game_state_t *game, char tile);
unsigned int is_wall(game_state_t *game, char tile);
unsigned char tile_is_passable(game_state_t *game, int index);
#endif