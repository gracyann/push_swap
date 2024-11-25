NAME		= push_swap

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

LIBFT		= ./libft/libft.a

SRCS		= main.c \
			init.c \
			error_handling.c \
			init_a.c \
			init_b.c \
			split.c \
			./Operations/push.c \
			./Operations/swap.c \
			./Operations/rotate.c \
			./Operations/reverse_rotate.c \
			./Operations/utils.c \
			./Operations/arrange_stacks.c \
			./Operations/arrange_three.c

OBJS 	= ${SRCS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all : ${NAME}

${NAME} : ${OBJS} ${LIBFT}
	${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME}

$(LIBFT):
					@make -C ./libft

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
