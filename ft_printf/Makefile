NAME = libftprintf.a

SRCS = ft_printf.c \
	ft_putstr.c \
	ft_putchar.c \
	ft_putnbr.c \
	ft_putunsigned.c \
	ft_putnbr_base.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "ft_printf: Compiling Completed."
	@echo "ft_printf: Linking $(NAME)..."
	@ar rcs $(NAME) $(OBJS)
	@echo "ft_printf: Linking Completed."

$(OBJS): $(SRCS)
	@echo "ft_printf: Compiling $<..."
	@cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@echo "ft_printf: Cleaning up..."
	@rm -rf $(OBJS)
	@echo "ft_printf: Cleaning Completed."

fclean: clean
	@echo "ft_printf: Removing $(NAME)..."
	@rm -rf $(NAME)
	@echo "ft_printf: Removing Completed."

re: fclean all