SRCS = $(addprefix src/, push_swap.c move.c list_init.c tri_selectif.c parsing_utils.c move_2.c tri_3.c compteur_coups.c daron.c)

NAME = push_swap

INC = -Iincludes

FLAGS = -g3 #-Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

LIBFT = libft.a

${NAME} : ${OBJS} ${LIBFT}
			make -C libft/ all
			mv libft/libft.a ./
			gcc ${FLAGS} ${INC} $(OBJS) -o $(NAME) libft.a

${LIBFT}:
	make -C libft/ all
	mv libft/libft.a ./

all : ${NAME}

%.o:%.c
		gcc ${FLAGS} ${INC}  -c $< -o $@

clean :
		make -C ./libft/ clean
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME} ${LIBFT}
		make -C ./libft/ fclean

re : fclean all

.PHONY : all clean fclean re libft 