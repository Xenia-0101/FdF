NAME = fdf
CFLAGS =  -g
# CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = ./MLX42
MLX_LIB = $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -Ofast

GCC = -DCMAKE_C_COMPILER=/usr/bin/gcc
GPP = -DCMAKE_CXX_COMPILER=/usr/bin/g++

HEADER = -I ./includes/

RM = rm -rf
CC = cc
AR = ar rc

# TODO: move main.c to the root of the project
SOURCES := \
			main.c\
			src/ft_bresenham.c\
			src/ft_put_points.c\
			src/keyboard_hook.c\
			src/test.c\

# SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

all: libmlx ${NAME}
	@echo "FdF executable is ready"

libmlx:
	@cmake $(MLX_DIR) ${GCC} ${GPP} -B ${MLX_DIR}/build
	@make -C ${MLX_DIR}/build -j4
	@echo "MLX42 library is ready"

%.o: %.c
		@${CC} ${CFLAGS} -c $< $(HEADER) -o $@

${NAME}: ${OBJECTS}
		${CC} -o ${NAME} ${OBJECTS} ${MLX_LIB}

clean:
		${RM} ${OBJECTS}
		${RM} ${MLX_DIR}/build

fclean: clean
		${RM} ${NAME}

re: fclean all

# .PHONY: all clean fclean re libmlx

# ls *.c | sed 's/$/\\/'