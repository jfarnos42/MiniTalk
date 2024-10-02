NAME = libft.a

SRC = 	ft_calloc.c ft_atoi.c ft_strnstr.c ft_putchar_fd.c ft_bzero.c \
		ft_isalnum.c  ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memchr.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c  ft_strlcpy.c \
		ft_strlcat.c  ft_strlen.c ft_strncmp.c ft_strrchr.c  ft_tolower.c \
		ft_toupper.c ft_memcmp.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_atof.c ft_strcmp.c ft_atol.c ft_strappend.c
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstmap_bonus.c 

OBJ_DIR = obj
B_OBJ_DIR = b_obj

OBJ	= $(addprefix ${OBJ_DIR}/, ${SRC:%.c=%.o})
B_OBJ = $(addprefix ${B_OBJ_DIR}/, ${SRC_BONUS:%.c=%.o})

FLAGS = -Wall -Werror -Wextra

all: ${NAME}

${OBJ_DIR}/%.o:./%.c
	@mkdir -p ${OBJ_DIR}
	@gcc ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	@ar -crs ${NAME} ${OBJ}


${B_OBJ_DIR}/%.o:./%.c
	@mkdir -p ${B_OBJ_DIR}
	@gcc ${FLAGS} -c $< -o $@

bonus: ${B_OBJ} ${OBJ}
	@ar -crs ${NAME} ${B_OBJ}

clean:
	@rm -rf ${OBJ_DIR}
	@rm -rf ${B_OBJ_DIR}

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus