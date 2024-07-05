NAME_1 = server
NAME_2 = client
DIR_SRC = ./source
DIR_PRINTF = ./source/ft_printf
PRINTF = $(DIR_PRINTF)/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(DIR_SRC) -I $(DIR_PRINTF)/Include
RM = rm -rf

SRC_1 =	$(DIR_SRC)/server.c
SRC_2 = $(DIR_SRC)/client.c \
		$(DIR_SRC)/ft_atoi.c

OBJ_1 = $(SRC_1:.c=.o)
OBJ_2 = $(SRC_2:.c=.o)

all: $(PRINTF) $(NAME_1) $(NAME_2)

$(PRINTF):
	make all -C $(DIR_PRINTF)

$(NAME_1): $(OBJ_1)
	$(CC) $(CFLAGS) $(OBJ_1) $(PRINTF) -o $(NAME_1)

$(NAME_2): $(OBJ_2)
	$(CC) $(CFLAGS) $(OBJ_2) $(PRINTF) -o $(NAME_2)

$(DIR_SRC)/%.o: $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_1) $(OBJ_2)
	make clean -C $(DIR_PRINTF)

fclean: clean
	$(RM) $(NAME_1) $(NAME_2)
	make fclean -C $(DIR_PRINTF)

re: fclean all

.PHONY: all clean fclean re