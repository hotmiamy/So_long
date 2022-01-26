NAME = so_long.out

FLAGS  = -Wall -Wextra -Werror
INCLUDES = -lmlx -lX11 -lXext

SRC = main.c map.c load_game.c
OBJ = *.o

LIBFT = ./libft/libft.a

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(LIBFT) 
	@ echo $(CURSIVE) $(GRAY) " - Compiling $(NAME)..." $(NONE)
	@ clang $(addprefix ./src/,$(SRC)) $(FLAGS) -g3 $(INCLUDES) -L ./libft -lft -o $(NAME)
	@ echo $(GREEN)" - Compiled - " $(NONE)

$(LIBFT): 
	make all -C ./libft
	make clean -C ./libft

$(OBJ): $(SRC)
	@ echo $(CURSIVE) $(GRAY) " - Making object files..." $(NONE)
	@ clang $(FLAGS) -c $(addprefix ./src/,$(SRC))

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file=log_valgrind ./$(NAME)

clean:
	@ echo $(CURSIVE) $(GRAY) " - Removing Object files..." $(NONE)
	@ rm -rf $(OBJ)

fclean: clean
	@ echo $(CURSIVE) $(GRAY) " - removing $(NAME)..." $(NONE)
	@ rm -rf $(NAME)

re: fclean all