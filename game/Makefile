##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Modular Makefile for Sokoban project
##

.PHONY: all clean fclean re

CC							=	gcc
MAKEFLAGS					=	--silent
CFLAGS						=	-I../lib/headers/										\
								-I../lib/headers/funs/									\
								-I./headers/											\
								-I./headers/runtime/									\
								-I./headers/errors/										\
								-I./headers/structs/									\
								-I./headers/config/										\
								-Wall													\
								-Wextra													\
								-Ofast

LDFLAGS						=	-L../ -lmy -lncurses
EXECUTABLE_NAME				=	my_sokoban

MAKE_LIB					=	../lib/
BIN_PATH					=	..
SRC_FOLDER					=	src
ERR_HANDLING_FOLDER			=	$(SRC_FOLDER)/error_handling
ERR_MSG_FOLDER				=	$(ERR_HANDLING_FOLDER)/errors_msg
RUNTIME_FOLDER				=	$(SRC_FOLDER)/runtime

SOKOBAN_SRC					= 															\
								$(SRC_FOLDER)/main.c									\
								$(ERR_HANDLING_FOLDER)/error_handling.c					\
								$(ERR_HANDLING_FOLDER)/maps_checkers/map_checker.c		\
								$(ERR_MSG_FOLDER)/usage_msg.c							\
								$(ERR_MSG_FOLDER)/failed_to_malloc_msg.c				\
								$(ERR_MSG_FOLDER)/unable_to_open_file_msg.c				\
								$(ERR_MSG_FOLDER)/invalid_map_file_msg.c				\
								$(ERR_MSG_FOLDER)/invalid_char_msg.c					\
								$(ERR_MSG_FOLDER)/less_slots_than_boxes_msg.c			\
								$(ERR_MSG_FOLDER)/missing_starting_position_msg.c		\
								$(ERR_MSG_FOLDER)/more_slots_than_boxes_msg.c			\
								$(ERR_MSG_FOLDER)/too_much_starting_positions_msg.c		\
								$(RUNTIME_FOLDER)/run.c									\
								$(RUNTIME_FOLDER)/game_loop_exceptions.c				\
								$(RUNTIME_FOLDER)/create_map_infos.c					\
								$(RUNTIME_FOLDER)/char_movements_manager.c				\
								$(RUNTIME_FOLDER)/char_neighbor.c						\
								$(RUNTIME_FOLDER)/drawers.c								\
								$(RUNTIME_FOLDER)/tile_manager.c						\
								$(RUNTIME_FOLDER)/handle_win.c							\
								$(RUNTIME_FOLDER)/handle_game_over.c					\
								$(RUNTIME_FOLDER)/handlers.c							\
								$(RUNTIME_FOLDER)/initializers.c						\
								$(RUNTIME_FOLDER)/getters.c								\
								$(RUNTIME_FOLDER)/terminate.c

SOKOBAN_OBJ					=	$(SOKOBAN_SRC:.c=.o)

all:	$(SOKOBAN_OBJ)
			@$(MAKE) -C $(MAKE_LIB)
			@$(CC) -o $(BIN_PATH)/$(EXECUTABLE_NAME) $(SOKOBAN_OBJ) $(LDFLAGS)

clean:
			@$(MAKE) -C $(MAKE_LIB) fclean
			@rm -f $(SOKOBAN_OBJ)

fclean:	clean
			@rm -rf $(BIN_PATH)/$(EXECUTABLE_NAME)

re:		fclean all
