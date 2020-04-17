NAME	= 	lib_arcade_centipede.so

CXX 	= 	g++

RM 		= 	rm -f

SRCS 	=	src/Centipede.cpp				\
			../src/Entity.cpp		\
			../src/GameData.cpp		\

OBJS 	= 	$(SRCS:.cpp=.o)

CXXFLAGS = -W -Wall -Wextra -std=c++11 -fPIC -I../../include/ -I../include/ -Iinclude/

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(CXX) -shared -o $(NAME) $(OBJS) $(CXXFLAGS)

clean:
			$(RM) $(OBJS)

fclean:  	clean
			$(RM) $(NAME)

re:  		fclean all clean

debug:		CFLAGS+= -g
debug:		re

.PHONY:  	all clean fclean re