NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g3 -fsanitize=address
RM = rm -rf

### SOURCES ###
CLIENT_SRC = client.c
SERVER_SRC = server.c

BIN = bin
CLIENT_OBJ = $(BIN)/client.o
SERVER_OBJ = $(BIN)/server.o

CLIENT_EXE = client
SERVER_EXE = server
###############

### MODULES ###
FT_PRINTF_DIR = ./includes/Libft/modules/ft_printf/
FT_PRINTF_LIB = $(FT_PRINTF_DIR)libftprintf.a
LIBFT_DIR =		./includes/Libft/
LIBFT_LIB =		$(LIBFT_DIR)libft.a
###############

### COLORS ####
RED = \033[0;31m
YELLOW = \033[0;33m
GREEN = \033[0;32m
END_LINE = \033[0m
###############

all: $(LIBFT_LIB) $(CLIENT_EXE) $(SERVER_EXE)
	@echo
	@echo	"	███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗"
	@echo	"	████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝"
	@echo	"	██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ "
	@echo	"	██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ "
	@echo	"	██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗"
	@echo	"	╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"
	@echo
	@echo	"							by jfarnos-"
	@echo
	@echo

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(CLIENT_EXE): $(CLIENT_OBJ) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(YELLOW)Compiling Client$(END_LINE)"
	@${CC} ${CFLAGS} $^ -o $@
	@echo "$(GREEN)Client successfully compiled.$(END_LINE)"

$(SERVER_EXE): $(SERVER_OBJ) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(YELLOW)Compiling Server...$(END_LINE)"
	@${CC} ${CFLAGS} $^ -o $@
	@echo "$(GREEN)Server successfully compiled.$(END_LINE)"

${BIN}/%.o: %.c
	@mkdir -p ${BIN}
	@${CC} ${CFLAGS} -c $< -o $@
	@echo

clean:
	@echo
	@${MAKE} -C $(LIBFT_DIR) fclean
	@$(RM) $(BIN)
	@$(RM) $(CLIENT_EXE) $(SERVER_EXE) $(LIBFT_LIB)
	@echo
	@echo "$(GREEN)Objects and executables successfully removed.$(END_LINE)"

fclean: clean

bonus: re

debug: CFLAGS += $(DEBUG)
debug: re

re: fclean all

.PHONY: all clean fclean re