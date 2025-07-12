NAME = fdf
BONUS_NAME = fdf_bonus
LIBS = libft/libft.a

SRCS = get_next_line/get_next_line_bonus.c \
		get_next_line/get_next_line_utils_bonus.c \
		src/ft_draw_pixel.c \
		src/ft_3d_point_calc.c \
		src/ft_get_map.c \
		src/ft_read_file.c \
		src/ft_set_window_len.c \
		src/ft_get_map_len.c \
		src/ft_free_funcs.c \
		src/ft_draw_line.c \

SRC_BONUS = ft_main_bonus.c \
		bonus/ft_move_map.c \
		bonus/ft_rotate_map.c \
		bonus/ft_key_controller.c \
		bonus/ft_zoom_map.c

all: $(NAME)

bonus: $(LIBS)
	@echo "fdf: Compiling bonus files..."
	@cc -Wall -Wextra -Werror $(SRCS) $(SRC_BONUS) $(LIBS) -o $(BONUS_NAME) -Iminilibx-linux -Iincludes -Ilibft -Iget_next_line -Lminilibx-linux -lmlx -lXext -lX11 -lm

$(NAME): $(LIBS) $(SRCS) ft_main.c
	@echo "fdf: Compiling $(NAME)..."
	@cc -Wall -Wextra -Werror ft_main.c $(SRCS) $(LIBS) -o $(NAME) -Iminilibx-linux -Iincludes -Ilibft -Iget_next_line -Lminilibx-linux -lmlx -lXext -lX11 -lm

$(LIBS):
	@echo "fdf: Compiling with libraries..."
	@make -C libft

clean:
	@make -C libft fclean

fclean: clean
	@echo "fdf: Removing $(NAME) and $(BONUS_NAME) if exist..."
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all
	@echo "fdf: Recompiling all files..."

.PHONY: all bonus clean fclean re test val cls