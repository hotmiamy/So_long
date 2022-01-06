NAME = so_long.out

FLAGS  = -Wall -Wextra -Werror
INCLUDES = -lmlx -lX11 -lXext

SRC = main.c
OBJ = *.o

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@ echo $(CURSIVE) $(GRAY) " - Compiling $(NAME)..." $(NONE)
	@ clang $(FLAGS) $(OBJ) $(INCLUDES) -o $(NAME)
	@ echo $(GREEN)" - Compiled - " $(NONE)

$(OBJ): $(SRC)
	@ echo $(CURSIVE) $(GRAY) " - Making object files..." $(NONE)
	@ clang $(FLAGS) -c $(SRC)

clean:
	@ echo $(CURSIVE) $(GRAY) " - Removing Object files..." $(NONE)
	@ rm -rf $(OBJ)

fclean: clean
	@ echo $(CURSIVE) $(GRAY) " - removing $(NAME)..." $(NONE)
	@ rm -rf $(NAME)

re: fclean all