CC		= gcc
CFLAGS	= -Wall -Wextra
SRCS	= auft_parth.c 
OBJS	= ${SRCS:.c=.o}
NAME	= BSQ
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
