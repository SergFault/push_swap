NAME = push_swap

SRC_FILES = main.c stack_processor.c utils.c sort_utils.c stack_utils.c \
			init.c args_split.c validation.c mem_utils.c args_utils.c \
			optimization_actions.c sort.c stack_splits.c perform.c \
			stack_processor_binary_ops.c stack_utils_a.c stack_utils_b.c
LIBFT_DIR = Libft
LIBFT = /Libft/libft.a
LIB			=	-L$(LIBFT_DIR) -lft
INCLUDES = includes
FLAGS		=	-Wall -Wextra -Werror -std=c99 -g #-fsanitize=leak \
-fsanitize=address

SRC = $(addprefix src/, ${SRC_FILES})

OBJS		= 	${SRC:.c=.o}

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $@

all : LIBFT $(NAME)

$(NAME):	$(OBJS) $(INCLUDES)/push_swap.h
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

LIBFT :
	make -C $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)