##
## EPITECH PROJECT, 2022
## makefile
## File description:
## root
##
SRC     =   ./event.c \
			./main.c \
			./setup_windows.c \
			./map1.c \
			./player.c \
			./player_movement.c

OBJ     =     $(SRC:.c=.o)

NAME 	=	rabbitgun

CFLAGS 	+= -Wall -I./include -g

CFCSFML += -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -I./include

all: $(OBJ)
	gcc -o ${NAME} $(OBJ) $(CFCSFML) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re :	fclean
	make all

exec : re 
	make clean
	./rabbitgun