CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj
SRC_DIR = src
PRINTF_DIR = ft_printf

CLIENT = client
SERVER = server
PRINTF = $(PRINTF_DIR)/libftprintf.a

CLIENT_OBJ = $(patsubst $(SRC_DIR)/client/%.c, $(OBJ_DIR)/client/%.o, $(wildcard $(SRC_DIR)/client/*.c))
SERVER_OBJ = $(patsubst $(SRC_DIR)/server/%.c, $(OBJ_DIR)/server/%.o, $(wildcard $(SRC_DIR)/server/*.c))

all: $(PRINTF) $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -L$(PRINTF_DIR) -lftprintf -o $(CLIENT)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) -L$(PRINTF_DIR) -lftprintf -o $(SERVER)

$(OBJ_DIR)/client/%.o: $(SRC_DIR)/client/%.c | $(OBJ_DIR)/client
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/server/%.o: $(SRC_DIR)/server/%.c | $(OBJ_DIR)/server
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/client:
	mkdir -p $(OBJ_DIR)/client

$(OBJ_DIR)/server:
	mkdir -p $(OBJ_DIR)/server

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
