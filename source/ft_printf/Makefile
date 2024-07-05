NAME = libftprintf.a
DIR = ./Include

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(DIR)
RM = rm -rf

SRC =	$(DIR)/ft_conversions.c				\
		$(DIR)/ft_printf.c					\
		$(DIR)/ft_printf_formats_cs%.c		\
		$(DIR)/ft_printf_formats_pointer.c	\
		$(DIR)/ft_printf_formats_diu.c		\
		$(DIR)/ft_printf_formats_xX.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(DIR)/%.o: $(DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re