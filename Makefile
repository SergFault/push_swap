# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sergey <sergey@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 15:05:36 by sergey            #+#    #+#              #
#    Updated: 2021/10/03 15:05:36 by sergey           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = clang

SRC_FILES 	= main.c stack_processor.c utils.c sort_utils.c stack_utils.c \
				init.c args_split.c validation.c mem_utils.c args_utils.c \
				optimization_actions.c sort.c stack_splits.c perform.c \
				stack_processor_binary_ops.c stack_utils_a.c stack_utils_b.c
LIBFT_DIR 	= Libft
LIBFT 		= ./Libft/libft.a
LIB			= -L./$(LIBFT_DIR) -lft
HDR			= includes/push_swap.h
FLAGS		= -Wall -Wextra -Werror -std=c99 #-g -fsanitize=leak \
-fsanitize=address
SRC 		= $(addprefix src/, ${SRC_FILES})
OBJS		= ${SRC:.c=.o}

%.o:		%.c $(HDR)
			$(CC) $(FLAGS) -c $< -o $@

all: 		make_lib build_all

build_all:	$(LIBFT) $(NAME)

$(NAME):	$(OBJS) $(HDR) $(LIBFT)
			$(CC) $(FLAGS) $(OBJS) -o $@ $(LIB)

val:		${NAME}
			valgrind \
				--leak-check=full \
				--show-leak-kinds=all \
				--track-origins=yes \
				--verbose \
				--log-file=valgrind-out.txt \
				./${NAME} 2 4 3 5 80 77 22
clean:
			make -C $(LIBFT_DIR) clean
			rm -f ${OBJS}
			rm -f valgrind-out.txt

fclean:		clean
			make -C $(LIBFT_DIR) fclean
			rm -f ${NAME}

re:			fclean all

make_lib:
			make -C $(LIBFT_DIR)
			make bonus -C $(LIBFT_DIR)

.PHONY: val re all clean fclean make_lib build_all