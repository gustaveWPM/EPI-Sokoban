/*
** EPITECH PROJECT, 2021
** getters.c
** File description:
** Runtime getters/retrieve
*/

#include "game_state_struct.h"
#include "runtime_tile_manager.h"
#include "str_verifications_funs.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <ncurses.h>

unsigned char get_key_dir(int key)
{
    if (key == KEY_UP)
        return (8);
    if (key == KEY_DOWN)
        return (2);
    if (key == KEY_LEFT)
        return (4);
    if (key == KEY_RIGHT)
        return (6);
    return (0);
}

unsigned char get_opposite_dir(unsigned char dir)
{
    if (dir == 2)
        return (8);
    if (dir == 8)
        return (2);
    if (dir == 4)
        return (6);
    if (dir == 6)
        return (4);
    return (0);
}

unsigned int get_player_index(game_state_t *game)
{
    unsigned int map_str_len = my_strlen(game->map_infos->map);

    for (unsigned int index = 0; index < map_str_len; index++) {
        if (is_player(game, game->map_infos->map[index]))
            return (index);
    }
    return (-1);
}

unsigned int get_map_width(char *map_str)
{
    unsigned int map_str_len = my_strlen(map_str);
    unsigned int i = 0;

    for (; i < map_str_len; i++)
        if ((map_str[i] == '\n' || map_str[i] == '\0'))
            break;
    if (i == 0)
        return (0);
    if (i > 0)
        return (i - 1);
    return (0);
}

char *get_map_str(char *map_path)
{
    int fd = 0;
    char *map_str = NULL;
    struct stat file_infos;

    fd = open(map_path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    stat(map_path, &file_infos);
    map_str = malloc((file_infos.st_size + 1) * sizeof(char));
    if (map_str == NULL) {
        close(fd);
        return (NULL);
    }
    map_str[file_infos.st_size] = '\0';
    read(fd, map_str, file_infos.st_size);
    close(fd);
    return (map_str);
}