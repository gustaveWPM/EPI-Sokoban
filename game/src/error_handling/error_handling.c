/*
** EPITECH PROJECT, 2021
** error_handling.c
** File description:
** Error handling
*/

#include "err_handling_funs.h"
#include "str_verifications_funs.h"
#include "runtime_getters.h"
#include "vocab.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char call_help_menu(char **argv)
{
    int i = 0;
    char display_help = 0;

    for (; argv[1][i] == ' ' || argv[1][i] == '\t'; i++);
    if (match_pattern(argv[1], "-h", i)
        || match_pattern(argv[1], "--help", i))
        display_help = 1;
    if (display_help) {
        usage_msg(0);
        return (1);
    }
    return (0);
}

char unable_to_open_file(char **argv)
{
    int fd = open(argv[1], O_RDONLY);

    if (fd == -1)
        return (1);
    close(fd);
    return (0);
}

char error_handling(int argc, char **argv)
{
    char *map_str = NULL;
    if (argc != 2) {
        usage_msg(1);
        return (1);
    }
    if (call_help_menu(argv))
        return (-1);
    if (unable_to_open_file(argv)) {
        unable_to_open_file_msg(argv);
        return (1);
    }
    map_str = get_map_str(argv[1]);
    if (map_str == NULL) {
        failed_to_malloc_msg();
        return (1);
    }
    if (invalid_map_file(map_str)) {
        invalid_map_file_msg();
        return (1);
    }
    return (0);
}