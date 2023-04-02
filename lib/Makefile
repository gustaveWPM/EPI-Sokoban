##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Modular Makefile for Sokoban project
##

MAKEFLAGS						=	--silent
LIB_ARCHIVE						=	../libmy.a
CFLAGS							=	-I./headers/

STR_FUNS_PATH					=	my/str_functions
DYN_STR_FUNS_PATH				=	$(STR_FUNS_PATH)/dyn_str_functions
STR_COUNTING_FUNS_PATH			=	$(STR_FUNS_PATH)/str_counting_funs
STR_PUTS_FUNS_PATH				=	$(STR_FUNS_PATH)/str_puts_funs
STR_VERIFICATIONS_FUNS_PATH		=	$(STR_FUNS_PATH)/str_verifications_funs

LIB_SRC							= 																	\
									$(STR_COUNTING_FUNS_PATH)/str_count_char.c						\
									$(STR_PUTS_FUNS_PATH)/my_putchar_on_stderr.c					\
									$(STR_PUTS_FUNS_PATH)/my_puterr.c								\
									$(STR_VERIFICATIONS_FUNS_PATH)/my_strlen.c						\
									$(STR_VERIFICATIONS_FUNS_PATH)/match_pattern.c					\
									$(STR_VERIFICATIONS_FUNS_PATH)/char_is_in_char_collection.c		\
									$(DYN_STR_FUNS_PATH)/my_strdup.c

LIB_OBJ							=	$(LIB_SRC:.c=.o)

../libmy.a:	$(LIB_OBJ)
			@ar rc ../libmy.a $(LIB_OBJ)

all:	$(LIB_ARCHIVE)

clean:
			@rm -f $(LIB_OBJ)

fclean:	clean
			@rm -f $(LIB_ARCHIVE)

re:		fclean all
