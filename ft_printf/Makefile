NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putchar.c\
 ft_putstr.c ft_putnbr_base.c\
 ft_putnbr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c $(HEADERS) Makefile
	$(CC) $(FLAGS) -c $< -o $@ -I .

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -rf $(NAME)

re: fclean 
	$(MAKE) $(NAME)

test:
	cd ft_printf_tester && sh test m && cd ..

.PHONY : all bonus clean fclean re