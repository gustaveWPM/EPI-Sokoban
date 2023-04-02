/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** Duplicates a str
*/

#include "my_lib.h"

char *my_strdup(char *str)
{
    int str_len;
    char *new_str;
    int i = 0;

    if (str == NULL)
        return (NULL);
    str_len = my_strlen(str);
    new_str = malloc((str_len + 1) * sizeof(char));
    if (new_str == NULL)
        return (NULL);
    for (i = 0; i < str_len; i++)
        new_str[i] = str[i];
    new_str[i] = '\0';
    return (new_str);
}