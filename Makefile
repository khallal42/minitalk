# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khallal <khallal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 10:45:10 by khallal           #+#    #+#              #
#    Updated: 2022/12/09 15:27:23 by khallal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
CFILES =  utils.c \
		  client.c \
		  server.c
FILES_BONUS = client_bonus.c \
			  server_bonus.c \
			  utils_bonus.c 		 
CC = gcc
FLAG = -Wall -Werror -Wextra
LI = ar -rc
RM = rm -rf
OBJ = ${CFILES:.c=.o}
OBJ1 = ${FILES_BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ} ${OBJ1}
	${LI} ${NAME} ${OBJ} ${OBJ1}

${OBJ} : 
	${CC} ${FLAG} -c  ${CFILES}
${OBJ1} : 
	${CC} ${FLAG} -c  ${FILES_BONUS}

clean :
	${RM} ${OBJ} ${OBJ1}

fclean : clean
	${RM} ${NAME}
re : fclean all