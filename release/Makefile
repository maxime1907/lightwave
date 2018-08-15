NAME	= lightwave

CC	= g++

RM	= rm -f

SRCS	=   ../src/main.cpp \
            ../src/Tile.cpp \
            ../src/Player.cpp \
	    ../src/TextBox.cpp \
	    ../src/Map.cpp \
	    ../src/GameManager.cpp \
	    ../src/Enemy.cpp \
	    ../src/ACharacter.cpp \
	    ../src/Animation.cpp \
	    ../src/Spawner.cpp \
            ../src/Life.cpp \
            ../src/Menu.cpp \
            ../src/Rune.cpp \
            ../src/Credits.cpp \


OBJS	= $(SRCS:.cpp=.o)

LDFLAGS = -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
CPPFLAGS = -I../src/include/
CPPFLAGS += -W -Wall -Wextra

ifeq ($(DEBUG), yes)
	CPPFLAGS += -g
endif

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
