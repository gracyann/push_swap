NAME = push_swap

CFLAGS = -Werror -Wall -Wextra 

RM = rm -rf

LIBFT_PATH	=	./libft

SRCS =  main.c \
		arrange_stacks.c \
		arrange_three.c \
		init_a.c \
		init_b.c \
		init.c \
		list_manip.c \
		error_handling.c \
		push.c \
		rotate.c \
		reverse_rotate.c \
		swap.c \
		utils.c \
		main_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_PATH)/libft.a

INCLUDE = -I include

all :	$(NAME)

$(NAME) :	$(OBJS) $(LIBFT)
		cc $(CFLAGS) $(OBJS) $(INCLUDE) $(LIBFT) -o $(NAME)

$(LIBFT) :
		@make -C $(LIBFT_PATH)

fclean : clean
				$(RM) $(NAME)
				make fclean -C $(LIBFT_PATH)

clean :
		$(RM) $(OBJS)
		make clean -C $(LIBFT_PATH)

re : fclean all