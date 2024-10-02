NAME = minitalk
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g3 -fsanitize=address
RM = rm -rf

### SOURCES ###
CLIENT_SRC = client.c
SERVER_SRC = server.c

OBJ_DIR = obj
CLIENT_OBJ = $(OBJ_DIR)/client.o
SERVER_OBJ = $(OBJ_DIR)/server.o

CLIENT_EXE = client
SERVER_EXE = server
###############

### MODULES ###
LIBFT_DIR =		./includes/Libft/
LIBFT_LIB =		$(LIBFT_DIR)libft.a
FT_PRINTF_DIR =	./includes/ft_printf/
FT_PRINTF_LIB = $(FT_PRINTF_DIR)libftprintf.a
###############

### COLORS ####
RED = \033[0;31m
YELLOW = \033[0;33m
GREEN = \033[0;32m
END_LINE = \033[0m
###############

all: $(LIBFT_LIB) $(FT_PRINTF_LIB) $(CLIENT_EXE) $(SERVER_EXE)
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

$(FT_PRINTF_LIB):
	@echo "$(YELLOW)Compiling FT_PRINTF...$(END_LINE)"
	@$(MAKE) -C $(FT_PRINTF_DIR)
	@echo "$(GREEN)FT_PRINTF successfully compiled.$(END_LINE)"

$(LIBFT_LIB):
	@echo "$(YELLOW)Compiling LIBFT...$(END_LINE)"
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)LIBFT successfully compiled.$(END_LINE)"

$(CLIENT_EXE): $(CLIENT_OBJ) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(YELLOW)Compiling client...$(END_LINE)"
	@${CC} ${CFLAGS} $^ -o $@
	@echo "$(GREEN)Client successfully compiled.$(END_LINE)"

$(SERVER_EXE): $(SERVER_OBJ) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(YELLOW)Compiling server...$(END_LINE)"
	@${CC} ${CFLAGS} $^ -o $@
	@echo "$(GREEN)Server successfully compiled.$(END_LINE)"

${OBJ_DIR}/%.o: %.c
	@mkdir -p ${OBJ_DIR}
	@${CC} ${CFLAGS} -c $< -o $@
	@echo

clean:
	@echo "================================================================"
	@echo "$(YELLOW)Cleaning FT_PRINTF...$(END_LINE)"
	@${MAKE} -C $(FT_PRINTF_DIR) fclean
	@echo "$(GREEN)FT_PRINTF object files removed.$(END_LINE)"
	@echo "$(YELLOW)Cleaning LIBFT...$(END_LINE)"
	@${MAKE} -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)LIBFT object files removed.$(END_LINE)"
	@echo "$(YELLOW)Cleaning objects and executables...$(END_LINE)"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(CLIENT_EXE) $(SERVER_EXE)
	@echo "$(GREEN)Objects and executables successfully removed.$(END_LINE)"

fclean: clean

debug: CFLAGS += $(DEBUG)
debug: re

re: fclean all

.PHONY: all clean fclean re