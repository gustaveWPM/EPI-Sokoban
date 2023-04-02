/*
** EPITECH PROJECT, 2021
** game_state_struct.h
** File description:
** Game State Structure
*/

#ifndef GAME_STATE_STRUCT_H
#define GAME_STATE_STRUCT_H
#include "map_infos_struct.h"
#include "map_symbols_struct.h"
typedef struct {
    int key_pressed;
    unsigned char done;
    unsigned char paused;
    char won;
    unsigned char direction;
    int term_cols;
    int term_lines;
    char running_ncurses;
    map_infos_t *map_infos;
    map_symbols_t *map_symbols;
} game_state_t;
#endif