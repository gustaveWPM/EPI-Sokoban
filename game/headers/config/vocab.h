/*
** EPITECH PROJECT, 2021
** vocab.h
** File description:
** Vocabulary
*/

#ifndef VOCAB_H
#define VOCAB_H
#define USAGE_MSG "USAGE\n\
\t./my_sokoban map\n\
DESCRIPTION\n\
\tmap file representing the warehouse map, containing '#' for walls,\n\
\t    'P' for the player, 'X' for boxes and 'O' for storage locations.\n"
#define UNABLE_TO_OPEN_FILE_MSG "Unable to open file: "
#define INVALID_MAP_FILE_MSG "Invalid mapfile.\n"
#define INVALID_CHAR_MSG "Unexpected token in mapfile: "
#define TOO_MUCH_STARTING_POSITIONS_MSG "\
Unexpected token: P (multiple starting positions).\n\
Expected only one 'P' token.\n"
#define MISSING_STARTING_POSITION_MSG "Missing starting position.\n\
Expected one 'P' token. Found none.\n"
#define LESS_SLOTS_THAN_BOXES_MSG "Found less slots than boxes.\n\
Expected equal amount of 'X' tokens than 'O' tokens.\n"
#define MORE_SLOTS_THAN_BOXES_MSG "Found more slots than boxes.\n\
Expected equal amount of 'X' tokens than 'O' tokens.\n"
#define MAP_INFOS_ERRORS_SEPARATOR "----\n"
#define INVALID_MAP_WIDTH_MSG "\
Invalid map width: \
each lines should contain the same amount of characters.\n"
#define RESIZE_TERM_MSG "Please, resize your terminal"
#define YOU_WON_MSG "Congrats! You WON!\n"
#define YOU_LOSE_MSG "T'es vraiment NUL !\n"
#define FAILED_TO_MALLOC_MSG "Failed to malloc\n"
#endif