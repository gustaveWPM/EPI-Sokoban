/*
** EPITECH PROJECT, 2021
** tile_manager.c
** File description:
** Basic tiles functions
*/

#include "game_state_struct.h"

unsigned int is_wall(game_state_t *game, char tile)
{
    if (tile == game->map_symbols->wall_symbol)
        return (1);
    return (0);
}

unsigned int is_ground(game_state_t *game, char tile)
{
    if (tile == game->map_symbols->ground_symbol)
        return (1);
    return (0);
}

unsigned int is_player(game_state_t *game, char tile)
{
    if (tile == game->map_symbols->player_symbol)
        return (1);
    return (0);
}

unsigned int is_box(game_state_t *game, char tile)
{
    if (tile == game->map_symbols->box_symbol)
        return (1);
    return (0);
}

unsigned int is_slot(game_state_t *game, char tile)
{
    if (tile == game->map_symbols->slot_symbol)
        return (1);
    return (0);
}
