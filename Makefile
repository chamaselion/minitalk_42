NAME_CLIENT = client
NAME_SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
CLIENT_SRCS = client.c
SERVER_SRCS = server.c

# Object files
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

# Library
LIBFT = libft/libft.a

all: $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	$(MAKE) -C ./libft all

# Target to build the client executable
$(NAME_CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

# Target to build the server executable
$(NAME_SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re