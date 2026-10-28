NAME			= ft_malcolm
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g -I$(HDR_DIR)

SRC_DIR			= srcs
OBJ_DIR			= obj
HDR_DIR			= includes

SRCS		= main.c parsing.c socket.c listen.c reply.c signal.c utils.c

OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INCLUDES		= $(HDR_DIR)/ft_malcolm.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re