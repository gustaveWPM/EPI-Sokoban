/*
** EPITECH PROJECT, 2021
** errors_msg.h
** File description:
** Errors message
*/

#ifndef ERRORS_MSG_H
#define ERRORS_MSG_H
void usage_msg(unsigned char is_error);
void failed_to_malloc_msg(void);
void invalid_map_file_msg(void);
void too_much_starting_positions_msg(char);
void missing_starting_position_msg(char);
void less_slots_than_boxes_msg(char);
void more_slots_than_boxes_msg(char);
void invalid_char_msg(char);
void unable_to_open_file_msg(char **);
#endif