/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Entry point
*/

#include "err_handling_funs.h"
#include "runtime_core.h"

int main(int argc, char **argv)
{
    char *map_path = argv[1];
    char error_handling_ret = error_handling(argc, argv);

    if (error_handling_ret == 1)
        return (84);
    if (error_handling_ret == -1)
        return (0);
    return (run(map_path));
}