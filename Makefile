NAME = so_long

CC = gcc
CFLAGS  = -Wall -Wextra -Werror -g3
INCLUDES = -lmlx -lX11 -lXext

SRC_FILES = main.c map.c load_game.c validate.c close_game.c player.c gameplay.c camera.c
SRC = $(addprefix ./src/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
HEADER = so_long.h

LIBFT = ./libft/libft.a

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(OBJ): %.o : %.c
	@ echo $(CURSIVE) $(GRAY) " - Making object files..." $(NONE)
	@ $(CC) $(CFLAGS)  -o $@ -c $<

$(NAME): $(OBJ) $(LIBFT) $(HEADER)
	@ echo $(CURSIVE) $(GRAY) " - Compiling $(NAME)..." $(NONE)
	@ $(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(INCLUDES) -o $(NAME)
	@ echo $(GREEN)" - Compiled - " $(NONE)

$(LIBFT):
	@ echo $(CURSIVE) $(GRAY) " - Compiling $(LIBFT)..." $(NONE)
	@ make all -C ./libft

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --log-file=log_valgrind ./$(NAME) ./maps/wrong_lenght_map.ber

debug:
	gdb so_long

out:
	./so_long

clean:
	@ echo $(CURSIVE) $(GRAY) " - Removing Object files..." $(NONE)
	@ make clean -C ./libft
	@ rm -rf $(OBJ)

fclean: clean
	@ echo $(CURSIVE) $(GRAY) " - removing $(NAME)..." $(NONE)
	@ make fclean -C ./libft
	@ rm -rf $(NAME)

re: fclean all