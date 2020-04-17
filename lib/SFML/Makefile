NAME = lib_arcade_sfml.so

CXX = g++

RM = rm -f

SRCS =	src/SFMLLib.cpp		\
		src/SFMLEntity.cpp	\
		src/SFMLSound.cpp

OBJS = $(SRCS:.cpp=.o)

LXXFLAGS = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
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