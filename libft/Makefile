NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = cc

SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strnstr.c \
	ft_strncmp.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c
OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c
BONUS_OBJS = $(BONUS:.c=.o)


GREEN=\033[0;32m
SET_DEF=\033[0m

all: $(NAME)

$(NAME): $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS) && \
	echo "${GREEN}libft: Compilation and linking successful!${SET_DEF}"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "${GREEN}libft: Cleaning Completed.${SET_DEF}"

fclean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -f $(NAME)
	@echo "${GREEN}libft: Removing Completed.${SET_DEF}"

re: fclean all

.PHONY: all clean fclean re