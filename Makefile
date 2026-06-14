NAME = miniRT

CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

SRCS = main.c \
       utils/math_utils.c \
       utils/vec_utils.c \
       camera_init.c \
       get_next_line.c \
       get_next_line_utils.c \
       lighting.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean 2>/dev/null || true
	make -C $(LIBFT_DIR) clean 2>/dev/null || true

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_DIR)/libft.a

re: fclean all

.PHONY: all clean fclean re