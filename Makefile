NAME = fdf
LIBS = libft/libft.a

SRCS = main.c \
		get_next_line/get_next_line_bonus.c \
		get_next_line/get_next_line_utils_bonus.c \
		src/ft_draw_pixel.c \
		src/ft_3d_point_calc.c \
		src/ft_get_map.c \
		src/ft_read_file.c \
		src/ft_set_window_len.c \
		src/ft_get_map_len.c \
		src/ft_free_funcs.c

all: $(NAME)

$(NAME): $(LIBS) $(SRCS)
	@echo "fdf: Compiling $(NAME)..."
	@cc -Wall -Wextra -Werror $(SRCS) $(LIBS) -o $(NAME) -Iminilibx-linux -Iincludes -Ilibft -Iget_next_line -Lminilibx-linux -lmlx -lXext -lX11 -lm

$(LIBS):
	@echo "fdf: Compiling with libraries..."
	@make -C libft

clean:
	@make -C libft fclean

fclean: clean
	@echo "fdf: Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

# This was for test must be deleted before finishing the project
test: all
	@echo "fdf: Running tests..."
	@./$(NAME) test_maps/42.fdf
val: all
	@echo "fdf: Running valgrind..."
	@- valgrind --leak-check=full ./$(NAME) test_maps/42.fdf > valgrind 2>&1 ; awk '/Invalid|uninitialised|LEAK SUMMARY|ERROR SUMMARY/ {p=1} p; /^==[0-9]+== $$/{p=0}' valgrind || echo "Hata tespit edilmedi."
cls: fclean
	@echo "fdf: Cleaning up..."
	@rm -f valgrind
norm:
	@echo "fdf: Running norminette..."
	@c_formatter_42 $(SRCS)
	@norminette $(SRCS)

.PHONY: all clean fclean re test val cls