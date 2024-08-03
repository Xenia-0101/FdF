NAME = fdf
CFLAGS =  -g
# CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf
CC = cc
AR = ar rc

# *** mlx library *** #
MLX_DIR = ./MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast

GCC = -DCMAKE_C_COMPILER=/usr/bin/gcc
GPP = -DCMAKE_CXX_COMPILER=/usr/bin/g++

# *** libft library *** #
LIBFT_DIR = libft
LIBFT_NAME = libft.a

# *** source code files *** #
SRC := \
		main.c\
		src/ft_bresenham.c\
		src/ft_put_points.c\
		src/keyboard_hook.c\
		src/test.c\

OBJ = $(SRC:.c=.o)
HEADER = -I ./includes/

all: libft libmlx ${NAME}
		@echo "FdF executable is ready"

%.o: %.c
		@${CC} ${CFLAGS} -c $< $(HEADER) -o $@

${NAME}: ${OBJ}
		${CC} -o ${NAME} ${OBJ} libft.a ${MLX_LIB}

# *** compile mlx42 *** #
libmlx:
	@cmake $(MLX_DIR) ${GCC} ${GPP} -B ${MLX_DIR}/build
	@make -C ${MLX_DIR}/build -j4
	@echo "MLX42 library is ready"

# *** compile libft *** #
libft:
	@make bonus -C libft
	@cp libft/libft.a ./
	@echo "libft library is ready"

# *** general rules *** #
clean:
		${RM} ${OBJ}
		${RM} ${MLX_DIR}/build
		make clean -C ${LIBFT_DIR}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re libmlx libft

# ls *.c | sed 's/$/\\/'