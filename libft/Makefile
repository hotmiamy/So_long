SRCFILES ?= ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c
SRCFILES += ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcat.c
SRCFILES += ft_strlcpy.c ft_strlen.c ft_toupper.c ft_tolower.c ft_strchr.c
SRCFILES += ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c
SRCFILES += ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c
SRCFILES += ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c
SRCFILES += ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
SRCFILES += ft_base_converter.c ft_uitoa.c ft_gnl.c

OBJFILES = $(SRCFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = libft.a

AR = ar
RM = rm -f
ARFLAGS = rcs

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

.c.o:
	@ echo $(CURSIVE) $(GRAY) " - Making object files of $(NAME)..." $(NONE)
	@ $(CC) $(CFLAGS) -c $^


$(NAME): $(OBJFILES)
	@ echo $(CURSIVE) $(GRAY) " - Compiling $(NAME)..." $(NONE)
	@ $(AR) $(ARFLAGS) $(NAME) $(OBJFILES)
	@ echo $(GREEN)" - Compiled - " $(NONE)

all: $(NAME)

re: fclean all

clean:
	@ echo $(CURSIVE) $(GRAY) " - Removing Object files of $(NAME)..." $(NONE)
	@ $(RM) $(OBJFILES)

fclean: clean
	@ echo $(CURSIVE) $(GRAY) " - removing $(NAME)..." $(NONE)
	@ $(RM) $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCFILES)
	gcc -nostartfiles -shared -o libft.so $(OBJFILES)

.PHONY: all re clean fclean
