NAME = so_long.out

FLAGS  = -Wall -Wextra -Werror
INCLUDES = -lmlx -lX11 -lXext

SRC = $(addprefix ./src/, $(SRC_FILES))
SRC_FILES = main.c map.c load_game.c validate.c
OBJ = $(SRC:src/.c=src/.o)

LIBFT = ./libft/libft.a

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

$(OBJ)/%.o: $(SRC)
	@ echo $(CURSIVE) $(GRAY) " - Making object files..." $(NONE)
	clang $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	@ echo $(CURSIVE) $(GRAY) " - Compiling $(NAME)..." $(NONE)
	clang $(FLAGS) $(OBJ) $(LIBFT) -g3 $(INCLUDES) -o $(NAME)
	@ echo $(GREEN)" - Compiled - " $(NONE)

$(LIBFT): 
	make all -C ./libft

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file=log_valgrind ./$(NAME)

gbd:


clean:
	@ echo $(CURSIVE) $(GRAY) " - Removing Object files..." $(NONE)
	@ rm -rf $(OBJ)

fclean: clean
	@ echo $(CURSIVE) $(GRAY) " - removing $(NAME)..." $(NONE)
	@ rm -rf $(NAME)

re: fclean all