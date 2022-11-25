##
## EPITECH PROJECT, 2022
## makefile
## File description:
## root
##
SRC     =   main.c

OBJ     =     $(SRC:.c=.o)

NAME 	=	rabbitgun

CFLAGS_csfml += -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

all: $(OBJ)
	gcc -o ${NAME} $(OBJ)  $(CFLAGS_csfml)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re :	fclean
	make all
