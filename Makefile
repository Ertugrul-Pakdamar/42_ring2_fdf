NAME = fdf

SRCS = main.c \
		src/ft_draw_pixel.c
OBJS = main.o \
		ft_draw_pixel.o

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	@echo "Compiling $(NAME)..."
	@cc -Wall -Wextra -Werror -c $(SRCS) -Iminilibx-linux -Iincludes -Lminilibx-linux -lmlx -lXext -lX11

clean:
	@echo "Cleaning up..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

# This was for test must be deleted before finishing the project
test: $(SRCS)
	@echo "Compiling $(NAME)..."
	@cc -Wall -Wextra -Werror $(SRCS) -o $(NAME) -Iminilibx-linux -Iincludes -Lminilibx-linux -lmlx -lXext -lX11
	@echo "Running tests..."
	@./$(NAME)

.PHONY: all clean fclean re