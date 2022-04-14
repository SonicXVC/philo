# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ameteori <ameteori@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 15:49:15 by ameteori          #+#    #+#              #
#    Updated: 2022/04/14 12:54:31 by ameteori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	philo

CC =	cc
CFLAGS =	-g -Werror -Wextra -Wall -MMD -pthread

RM =	rm -rf

SRC =		main.c\
			philo.c\
			utils.c\
			errors.c\
			game.c\
			time.c\

INCLUDE =	-I philo.h\

OBJ =	$(SRC:.c=.o)
D =		$(SRC:.c=.d)

.PHONY :	all clean re fclean

.c.o :		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJ) Makefile
				${CC} ${CFLAGS} ${LD_FLAGS} ${OBJ} -o ${NAME}

all:	$(NAME)

clean:
				$(RM) $(OBJ) $(D)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

-include $(D)