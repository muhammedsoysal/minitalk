SERVER= server
CLIENT= client
PRINTF_DIR= lib/printf
PRINTF_LIB= $(PRINTF_DIR)/libftprintf.a

NAME= all

CC= cc 
CFLAGS = -Wall -Werror -Wextra

RM= rm -rf

all: $(PRINTF_LIB) $(SERVER) $(CLIENT)

$(PRINTF_LIB):
	@make -C $(PRINTF_DIR)

$(SERVER): server.c
	$(CC) $(CFLAGS) server.c -o $(SERVER) $(PRINTF_LIB)

$(CLIENT): client.c
	$(CC) $(CFLAGS) client.c -o $(CLIENT) $(PRINTF_LIB)

clean:
	$(RM) $(SERVER) $(CLIENT)
	@make clean -C $(PRINTF_DIR)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	@make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re bonus