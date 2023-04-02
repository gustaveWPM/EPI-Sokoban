/*
** EPITECH PROJECT, 2021
** map_infos_struct.h
** File description:
** Map Infos Structure
*/

#ifndef MAP_INFOS_STRUCT_H
#define MAP_INFOS_STRUCT_H
typedef struct {
    char *memo_map;
    char *map;
    unsigned int height;
    unsigned int width;
    unsigned int boxes_amount;
    unsigned int slots_amount;
    unsigned int memo_player_index;
    unsigned int *memo_boxes_index;
    unsigned int *boxes_index;
    unsigned int *slots_index;
} map_infos_t;
#endif