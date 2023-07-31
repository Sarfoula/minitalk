CC = gcc
FLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj
SRC_DIR = src

CLIENT = client
SERVER = server

CLIENT_OBJ = $(patsubst $(SRC_DIR)/client/%.c, $(OBJ_DIR)/client/%.o, $(wildcard $(SRC_DIR)/client/*.c))
SERVER_OBJ = $(patsubst $(SRC_DIR)/server/%.c, $(OBJ_DIR)/server/%.o, $(wildcard $(SRC_DIR)/server/*.c))

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o $(CLIENT)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) -o $(SERVER)

$(OBJ_DIR)/client/%.o: $(SRC_DIR)/client/%.c | $(OBJ_DIR)/client
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/server/%.o: $(SRC_DIR)/server/%.c | $(OBJ_DIR)/server
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR)/client:
	mkdir -p $(OBJ_DIR)/client

$(OBJ_DIR)/server:
	mkdir -p $(OBJ_DIR)/server

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
