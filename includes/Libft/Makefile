NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g3 -fsanitize=address
RM = rm -rf

MAKEFLAGS += --no-print-directory

### SOURCES ###
LIB_SOURCES = ft_calloc.c ft_atoi.c ft_strnstr.c ft_putchar_fd.c ft_bzero.c \
				ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
				ft_strlcpy.c ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strrchr.c \
				ft_tolower.c ft_toupper.c ft_memcmp.c ft_strdup.c ft_substr.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
				ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_atof.c ft_strcmp.c ft_atol.c ft_strappend.c \
				ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

BIN = bin
OBJ	= $(addprefix ${BIN}/, ${LIB_SOURCES:%.c=%.o})

### MODULES ###
FT_PRINTF_DIR =	./modules/ft_printf/
FT_PRINTF_LIB = $(FT_PRINTF_DIR)libftprintf.a
GET_NEXT_LINE =	./modules/get_next_line/
GNL_LIB = $(GET_NEXT_LINE)get_next_line.a

### COLORS ####
RED = \033[0;31m
YELLOW = \033[0;33m
GREEN = \033[0;32m
END_LINE = \033[0m


all: $(NAME) $(FT_PRINTF_LIB) $(GNL_LIB)
$(NAME): $(OBJ)
	@ar rcs $@ $^

$(FT_PRINTF_LIB):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(GNL_LIB):
	@$(MAKE) -C $(GET_NEXT_LINE)

${BIN}/%.o: %.c
	@mkdir -p ${BIN}
	@${CC} ${CFLAGS} -c $< -o $@


clean:
	@echo
	@echo "$(YELLOW)Cleaning LIBFT...$(END_LINE)"
	@echo "$(YELLOW)		Cleaning FT_PRINTF...$(END_LINE)"
	@echo "$(YELLOW)		Cleaning GET_NEXT_LINE...$(END_LINE)"
	@$(RM) $(BIN)
	@${MAKE} -C $(GET_NEXT_LINE) fclean
	@${MAKE} -C $(FT_PRINTF_DIR) fclean
	@$(RM) $(NAME) $(FT_PRINTF_LIB) $(GNL_LIB)
	@echo
	@echo "$(GREEN)LIBFT object files removed.$(END_LINE)"


fclean: clean
debug: CFLAGS += $(DEBUG)
debug: re
re: fclean all

.PHONY: all clean fclean re
