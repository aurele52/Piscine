CC		= cc
CFLAGS	= -Wall -Wall -Wextra -Werror
SRCS	= main.c ft_parse1.c ft_final.c ft_print.c ft_print_sep.c ft_sep.c ft_fsize.c
OBJS	= ${SRCS:.c=.o}
NAME	= rush-02
RM		= rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re
