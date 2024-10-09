NAME = fdf
# CFLAGS =  -g
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf
CC = cc
AR = ar rc

MSG = "\
\n\
\033[0;32mThis project is about representing a landscape as a 3D object in which all surfaces are outlined in lines.\033[0m \n\
\n\
Things to try: \n\
\n\
\033[0;33mleft\033[0m   | move left \n\
\033[0;33mright\033[0m  | move right \n\
\033[0;33mup\033[0m     | move up \n\
\033[0;33mdown\033[0m   | move down \n\
\033[0;33mz\033[0m      | stretch \n\
\033[0;33mx\033[0m      | shrink \n\
\033[0;33m+\033[0m      | zoom in \n\
\033[0;33m-\033[0m      | zoom out \n\
\033[0;33ma, d\033[0m   | rotate around x axis \n\
\033[0;33mw, s\033[0m   | rotate around y axis \n\
\033[0;33mq, e\033[0m   | rotate around x = y axis \n\
\033[0;33m1\033[0m      | toggle projection isometric / oblique \n\
\033[0;33m7, 8\033[0m   | oblique projection parameters \n\
\033[0;33m4, 5\033[0m   | oblique projection parameters \n\
\033[0;33mesc\033[0m    | exit programme \n\
"

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
		main.c \
		src/ft_fdf_free.c \
		src/ft_fdf_init.c \
		src/ft_fdf_utils.c \
		src/ft_map_draw.c \
		src/ft_map_parse.c \
		src/ft_map_recalc.c \
		src/ft_map_transform.c \
		src/ft_map_utils.c \
		src/ft_math_bresenham.c \
		src/ft_math_mtrx_calc.c \
		src/ft_math_set_mtrx.c \
		src/ft_math_utils.c \
		src/keyboard_hook.c \
		src/ft_write_msg.c \

OBJ = $(SRC:.c=.o)
HEADER = -I ./include/

all: libft libmlx ${NAME}
	@echo "FdF executable is ready"
	@echo ${MSG}

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
	@make -C libft
	@mv libft/libft.a ./
	@echo "libft library is ready"

# *** general rules *** #
clean:
	${RM} ${OBJ}
	${RM} ${MLX_DIR}/build
	make clean -C ${LIBFT_DIR}

fclean: clean
	${RM} ${NAME} ${LIBFT_NAME}

re: fclean all

.PHONY: all clean fclean re libmlx libft

# ls *.c | sed 's/$/\\/'
