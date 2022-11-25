##
## EPITECH PROJECT, 2022
## makefile
## File description:
## root
##
SRC     =   ./event.c \
			./main.c \
			./setup_windows.c \

OBJ     =     $(SRC:.c=.o)

NAME 	=	rabbitgun

CFLAGS 	+= -Wall -I./include -g

CFCSFML += -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -I./include

all: $(OBJ)
<<<<<<< HEAD
	gcc -o ${NAME} $(OBJ) $(CFCSFML) $(CFLAGS)
=======
	gcc -o ${NAME} $(OBJ) $(CFLAGS_csfml)
>>>>>>> 8b6bbc7 (Map 1 and 2)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re :	fclean
	make all

exec : re 
	make clean
	./rabbitgun