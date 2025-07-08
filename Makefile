NAME = fdf
LIBS = libft/libft.a ft_printf/libftprintf.a

SRCS = main.c \
		get_next_line/get_next_line_bonus.c \
		get_next_line/get_next_line_utils_bonus.c \
		src/ft_draw_pixel.c \
		src/ft_3d_point_calc.c \
		src/ft_get_data.c \
		src/ft_read_file.c \

all: $(NAME)

$(NAME): $(LIBS) $(SRCS)
	@echo "fdf: Compiling $(NAME)..."
	@cc -Wall -Wextra -Werror $(SRCS) $(LIBS) -o $(NAME) -Iminilibx-linux -Iincludes -Ilibft -Ift_printf -Iget_next_line -Lminilibx-linux -lmlx -lXext -lX11 -lm

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
	@- valgrind --leak-check=full ./$(NAME)  > valgrind 2>&1 ; awk '/Invalid|uninitialised|LEAK SUMMARY|ERROR SUMMARY/ {p=1} p; /^==[0-9]+== $$/{p=0}' valgrind || echo "Hata tespit edilmedi."
cls: fclean
	@echo "fdf: Cleaning up..."
	@rm -f valgrind

.PHONY: all clean fclean re test val cls