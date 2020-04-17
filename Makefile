##
## EPITECH PROJECT, 2018
## Arcade
## File description:
## Makefile
##

CXX			= 	g++

SRC			=	core/src/Core.cpp		\
				menu/src/Menu.cpp		\
				games/src/Entity.cpp	\
				games/src/GameData.cpp	\
				Main.cpp

NAME		=	arcade

OBJ			=	$(SRC:.cpp=.o)

CXXFLAGS	=	-W -Wall -Wextra -Imenu/include/ -Iinclude/ -Icore/include/ -Igames/include/ -ldl

all:
			make core; make graphicals; make games

core:		$(OBJ)
			$(CXX) $(OBJ) -o $(NAME) $(CXXFLAGS)

caca:
			make re -C lib/CACA
			cp lib/CACA/lib_arcade_caca.so .

sdl:
			make re -C lib/SDL
			cp lib/SDL/lib_arcade_sdl.so .

sfml:
			make re -C lib/SFML
			cp lib/SFML/lib_arcade_sfml.so .

graphicals:
			make re -C lib/CACA
			cp lib/CACA/lib_arcade_caca.so .
			make re -C lib/SDL
			cp lib/SDL/lib_arcade_sdl.so .
			make re -C lib/SFML
			cp lib/SFML/lib_arcade_sfml.so .

nibbler:
			make re -C games/Nibbler
			cp games/Nibbler/lib_arcade_nibbler.so games/

centipede:
			make re -C games/centipede
			cp games/Centipede/lib_arcade_centipede.so games/

games:
			make re -C games/Nibbler
			cp games/Nibbler/lib_arcade_nibbler.so games/
			make re -C games/Centipede
			cp games/Centipede/lib_arcade_centipede.so games/


clean:
			rm -f $(OBJ)
			make clean -C lib/CACA
			make clean -C lib/SDL
			make clean -C lib/SFML
			make clean -C games/Nibbler
			make clean -C games/Centipede

fclean:		clean
			rm -f $(NAME)
			rm -f $(OBJ)
			make fclean -C lib/CACA
			make fclean -C lib/SDL
			make fclean -C lib/SFML
			rm -f *.so
			make fclean -C games/Nibbler
			make fclean -C games/Centipede
			rm -f games/*.so

re:			fclean all clean
			make fclean -C lib/CACA
			make re -C lib/CACA
			cp lib/CACA/lib_arcade_caca.so .
			make fclean -C lib/SFML
			make re -C lib/SFML
			cp lib/SFML/lib_arcade_sfml.so .
			make fclean -C lib/SDL
			make re -C lib/SDL
			cp lib/SDL/lib_arcade_sdl.so .
			make fclean -C games/Nibbler
			make re -C games/Nibbler
			cp games/Nibbler/lib_arcade_nibbler.so games/
			make fclean -C games/Centipede
			make re -C games/Centipede
			cp games/Centipede/lib_arcade_centipede.so games/


debug:		CFLAGS += -g
debug:		re

.PHONY:		all clean fclean re debug core caca sdl sdl2 sfml graphicals nibbler centipede games
