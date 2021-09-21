NAME = ft_push_swap

SRC_FILES = main.c stack_processor.c utils.c
LIBFT_DIR = Libft
LIBFT = ft
LIB			=	-L$(LIBFT_DIR) -lft
INCLUDES = includes
FLAGS		=	-Wall -Wextra -Werror -std=c99 -g #-fsanitize=leak \
-fsanitize=address

SRC = $(addprefix src/, ${SRC_FILES})

OBJS		= 	${SRC:.c=.o}

%.o:		%.c
			$(CC) $(FLAGS) -c $< -o $@

all : $(LIBRARY) $(NAME)

$(NAME):	$(OBJS) $(INCLUDES)/push_swap.h
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(LIBRARY) :
	make bonus -C $(LIBFT_DIR)