/*
** EPITECH PROJECT, 2020
** char_is_in_char_collection.c
** File description:
** Returns 1 if `c` is included in `collection`
*/

#include "my_lib.h"

char char_is_in_char_collection(char c, char *collection)
{
    int collection_size = my_strlen(collection);

    for (int i = 0; i < collection_size; i++) {
        if (c == collection[i])
            return (1);
    }
    return (0);
}
