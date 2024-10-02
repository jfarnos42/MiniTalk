NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

MAKEFLAGS += --no-print-directory

SRC = ft_printf.c ft_printf_utils.c \

BIN = bin
OBJ	= $(addprefix ${BIN}/, ${SRC:%.c=%.o})

all: $(NAME)

${NAME}: ${OBJ}
	@ar -crs ${NAME} ${OBJ}

${BIN}/%.o:./%.c
	@mkdir -p ${BIN}
	@$(CC) ${FLAGS} -c $< -o $@

clean:
	@$(RM) $(BIN)

fclean: clean
	@$(RM) $(NAME)

re: fclean all



.PHONY: all clean fclean re