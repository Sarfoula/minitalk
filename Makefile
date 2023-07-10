CLI = client
SRV = server

CC = gcc
FLAG = -Wall -Wextra -Werror

OBJ_DIR = obj
SRC_DIR = src

OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
SRC = $(wildcard $(SRC_DIR)/*.c)

$(NAME):
	make $(SRV)

$(SRV): $(OBJ_DIR)
	$(CC) $(OBJ) -o $(SRV)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile | $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(SRV)

re: fclean all

.PHONY: all clean fclean re