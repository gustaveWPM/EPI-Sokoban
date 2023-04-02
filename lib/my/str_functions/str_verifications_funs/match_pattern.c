/*
** EPITECH PROJECT, 2020
** match_pattern.c
** File description:
** Verifies a str match on an str char by char from an index
*/

#include "my_lib.h"

char str_includes_this_char(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (1);
    return (0);
}

char match_pattern(char *str, char *pattern, int index)
{
    int pattern_len = my_strlen(pattern);
    int str_len = my_strlen(str);
    int j = 0;

    if (pattern_len > str_len - index)
        return (0);
    for (int i = index; j < pattern_len; i++, j++) {
        if (str[i] != pattern[j])
            return (0);
    }
    return (1);
}