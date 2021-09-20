NAME = ft_push_swap

SRC_FILES = main.c

SRC = $(addprefix src/, ${SRC_FILES})

OBJS		= 	${SRC:.c=.o}


all : $(NAME)

$(NAME):	$(OBJS)
			make -C $(MLX_DIR)
			$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(NAME): $(OBJ) libft.h
	ar crs $(NAME) $?