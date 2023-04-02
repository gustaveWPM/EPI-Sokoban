##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

.PHONY: all clean fclean re

MAKEFLAGS		=	--silent
MAKE_SOKOBAN	=	game/

all clean fclean re:
	@$(MAKE) -C $(MAKE_SOKOBAN) $@
