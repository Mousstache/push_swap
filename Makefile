SRCS = $(addprefix src/, move.c list_init.c tri_selectif.c parsing_utils.c move_2.c tri_3.c compteur_coups.c daron.c calculs.c parsing_arg.c push_swap.c move_3.c)

SRCS_BONUS = $(addprefix bonus/, move.c list_init.c tri_selectif.c parsing_utils.c move_2.c tri_3.c compteur_coups.c daron.c calculs.c parsing_arg.c push_swap.c move_3.c new_move.c new_move2.c new_move3.c checker.c gnl.c )

NAME = push_swap

NAME_BONUS = checker

INC = -Iincludes

FLAGS = -g3 -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

LIBFT = libft.a

${NAME} : ${OBJS} ${LIBFT}
			make -C libft/ all
			mv libft/libft.a ./
			cc ${FLAGS} ${INC} $(OBJS) -o $(NAME) libft.a

${LIBFT}:
	make -C libft/ all
	mv libft/libft.a ./

all : ${NAME}

%.o:%.c
		cc ${FLAGS} ${INC}  -c $< -o $@

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS} ${LIBFT}
		cc ${FLAGS} ${INC} ${OBJS_BONUS} -o ${NAME_BONUS} ${LIBFT}

clean :
		make -C ./libft/ clean
		rm -rf ${OBJS} ${OBJS_BONUS}

fclean : clean
		rm -rf ${NAME} ${NAME_BONUS} ${LIBFT}
		make -C ./libft/ fclean

re : fclean all

.PHONY : all bonus clean fclean re bonus libft NAME NAME_BONUS
