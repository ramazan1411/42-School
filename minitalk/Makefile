NAME = minitalk
SERVER = server.c
CLIENT = client.c
SERVER_B = server_bonus.c
CLIENT_B = client_bonus.c
SERVER_NAME = server
CLIENT_NAME = client
SERVER_B_NAME = server_bonus
CLIENT_B_NAME = client_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

all: $(FT_PRINTF_LIB) $(SERVER_NAME) $(CLIENT_NAME)

$(FT_PRINTF_LIB):
	$(MAKE) CFLAGS="$(CFLAGS) -fPIC" -C $(FT_PRINTF_DIR)

$(SERVER_NAME): $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(SERVER) $(FT_PRINTF_LIB) -o $(SERVER_NAME)

$(CLIENT_NAME): $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(CLIENT) $(FT_PRINTF_LIB) -o $(CLIENT_NAME)

bonus: $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(SERVER_B) $(FT_PRINTF_LIB) -o $(SERVER_B_NAME)
	$(CC) $(CFLAGS) $(CLIENT_B) $(FT_PRINTF_LIB) -o $(CLIENT_B_NAME)

clean:
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(RM) $(SERVER_NAME) $(CLIENT_NAME) $(SERVER_B_NAME) $(CLIENT_B_NAME)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(RM) $(FT_PRINTF_LIB)

re: fclean all

.PHONY: all re fclean clean bonus
