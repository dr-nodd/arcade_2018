NAME = lib_arcade_sdl.so

CXX = g++

RM = rm -f

SRCS =	src/SDLLib.cpp		\
		src/SDLEntity.cpp

OBJS = $(SRCS:.cpp=.o)

LXXFLAGS = -lSDL -lSDL_ttf
CXXFLAGS = -W -Wall -Wextra -std=c++14 -fPIC -I../../include/ -Iinclude/ -I../../core/include/

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(CXX) -shared -o $(NAME) $(OBJS) $(LXXFLAGS) $(CXXFLAGS)

clean:
			$(RM) $(OBJS)

fclean:  	clean
			$(RM) $(NAME)

re:  		fclean all clean

debug:		CFLAGS+= -g
debug:		re

.PHONY:  	all clean fclean re