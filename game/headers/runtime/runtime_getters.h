/*
** EPITECH PROJECT, 2021
** runtime_getters.h
** File description:
** Runtime Getters
*/

#ifndef RUNTIME_GETTERS_H
#define RUNTIME_GETTERS_H
#include "game_state_struct.h"
char *get_map_str(char *map_path);
unsigned int get_player_index(game_state_t *game);
int get_dir_delta(game_state_t *game);
int get_char_neighbor_index(game_state_t *game, int index);
unsigned int get_map_width(char *map_str);
unsigned char get_opposite_dir(unsigned char dir);
unsigned char get_key_dir(int key);
#endif