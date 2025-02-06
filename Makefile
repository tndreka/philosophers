NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g -Iinclude

SRCS = src/main.c \
	   src/arg_check/argument_check.c \
	   src/initialization/init.c \
	   src/utils/utils.c \
	   src/utils/utils2.c \

OBJS = $(SRCS:.c=.o)

GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
NEU = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling...$(NEU)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Compiled!$(NEU)" || \
	@echo "$(RED)Failed!$(NEU)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



clean:
	@echo "$(RED)Cleaning object files...$(NEU)"
	rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Cleaning executable...$(NEU)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re