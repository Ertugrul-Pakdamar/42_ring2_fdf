NAME = fdf
LIBS = libft/libft.a ft_printf/libftprintf.a

SRCS = main.c \
		get_next_line/get_next_line_bonus.c \
		get_next_line/get_next_line_utils_bonus.c \
		src/ft_draw_pixel.c \
		src/ft_3d_point_calc.c \

all: $(NAME)

$(NAME): $(LIBS)
	@echo "fdf: Compiling $(NAME)..."
	@cc -Wall -Wextra -Werror $(SRCS) $(LIBS) -o $(NAME) -Iminilibx-linux -Iincludes -Ilibft -Ift_printf -Iget_next_line -Lminilibx-linux -lmlx -lXext -lX11

$(LIBS): $(OBJS)
	@echo "fdf: Compiling with libraries..."
	@make -C libft
	@make -C ft_printf

clean:
	@make -C libft fclean
	@make -C ft_printf fclean

fclean: clean
	@echo "fdf: Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

# This was for test must be deleted before finishing the project
test: all
	@echo "fdf: Running tests..."
	@./$(NAME)
val: all
	@echo "fdf: Running valgrind..."
	@valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re test val