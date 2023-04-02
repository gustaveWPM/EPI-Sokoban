/*
** EPITECH PROJECT, 2021
** str_count_char.c
** File description:
** Takes a char and counts its number of occurences in a str
*/

char str_count_char(char *str, char c)
{
    int counter = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            counter += 1;
    return (counter);
}