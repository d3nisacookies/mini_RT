NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

SRCS = src/main.c \
       src/render.c \
       src/scene_init.c \
       src/hooks.c \
       src/camera_init.c \
       src/lighting.c \
       src/is_in_shadow.c \
       src/parser/parser.c \
       src/parser/parse_ambient.c \
       src/parser/parse_camera.c \
       src/parser/parse_light.c \
       src/parser/parse_sphere.c \
       src/parser/parse_vector.c \
       src/parser/parse_utils.c \
       src/utils/math_utils.c \
       src/utils/vec_utils.c \
       src/utils/atof.c \
       gnl/get_next_line.c \
       gnl/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT)
	$(CC) $(CFLAGS) -no-pie $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) -Ignl -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean 2>/dev/null || true
	make -C $(LIBFT_DIR) clean 2>/dev/null || true

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/libft.a

re: fclean all

.PHONY: all clean fclean re