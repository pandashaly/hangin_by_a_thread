
# ==============COLORS=================
MAKEFLAGS += --silent
RED=\033[1;31m
GREEN=\033[1;32m
NC=\033[0m

# ===============FLAGS=================
CC = gcc
FLAGS = -Wall -Wextra -Werror -ggdb3 -g3 -pthread #-fsanitize=thread
RM = rm -rf
NAME = philo

SRC_DIR = src
INC = inc
IFLAGS = -I$(INC)

# ================SRCS=================
SRCS = main.c \
		run.c \
		init.c \
		utils.c \
		parser.c \
		routine.c \

OBJS = $(SRCS:.c=.o)

# ===============BUILD==================
all: $(NAME)

$(NAME): $(OBJS)
			$(CC) $(FLAGS) $(OBJS) $(IFLAGS) -o $(NAME)
	@echo "[$(GREEN)PHILOS$(NC)] - $<"

%.o: %.c
	echo "[$(GREEN)PHILOS$(NC)] - $<"
	$(CC) $(FLAGS) $(IFLAGS) -c $< -o $@

# ===============CLEAN==================
clean:
	@echo "[$(RED)PHILOS$(NC)] Cleaning object files..."
			@$(RM) $(OBJS)

fclean: clean
	@echo "[$(RED)PHILOS$(NC)] Cleaning executable file..."
			@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re