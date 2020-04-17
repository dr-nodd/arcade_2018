NAME	= 	lib_arcade_caca.so

CXX 	= 	g++

RM 		= 	rm -f

SRCS 	=	src/CacaLib.cpp		\
			src/CacaEntity.cpp

OBJS 	= 	$(SRCS:.cpp=.o)

LXXFLAGS = `pkg-config --libs --cflags caca`
CXXFLAGS = -W -Wall -Wextra -std=c++11 -fPIC -I../../include/ -Iinclude/ -I../../core/include/

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