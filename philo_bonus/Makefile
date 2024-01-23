# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 17:56:37 by maserrie          #+#    #+#              #
#    Updated: 2023/03/31 14:26:26 by maserrie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ALIAS

INC			= -I ./inc
CC 			= clang
RM 			= rm -fr
NAME 		= ./philo_bonus
CFLAGS 		= -Wall -Werror -Wextra -g
ifeq ($(shell uname), Linux)
	CFLAGS			+=	-pthread
else
#	CFLAGS += -fsanitize=address -fsanitize=undefined
endif

#COLOR

DEF_COLOR	=	\033[0;39m
ORANGE		=	\033[0;33m
GRAY		=	\033[0;90m
RED		=		\033[0;91m
GREEN		=	\033[1;92m
YELLOW		=	\033[1;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

#SRCS

MAIN =	philo.c ft_free.c ft_print.c ft_utils.c ft_spaghetti.c ft_thread.c ft_init.c\

SRCS = $(addprefix srcs/, ${MAIN})

OBJS = $(patsubst srcs%, obj%, $(SRCS:.c=.o))

#COMMANDES

all: obj ${NAME}

obj/%.o: srcs/%.c ${NAME}_functs
	@${CC} ${CFLAGS} ${INC} -o $@ -c $<
	@echo "Compiling ${CYAN}$< ${DEF_COLOR}"

obj:
	@mkdir -p obj/

${NAME}:: ${OBJS}
	@${CC} -o ${NAME} ${CFLAGS} ${OBJS} ${LIB}

${NAME}::
	@echo "${GREEN}${NAME}${DEF_COLOR} created"

bonus: all

clean:
	@${RM} ${OBJS}
	@${RM} obj
	@echo "${MAGENTA}Cleaning philo"

fclean: clean
	@${RM} ${NAME}

fdfclean:
	@${RM} ${OBJS}
	@${RM} obj
	@${RM} ${NAME}

philore: fdfclean all

re: fclean all

.PHONY = all clean fclean re

#LIBRAIRIES

%functs:
	@printf "${YELLOW} 🏁 🏁 Compiling $@ \033[5m[...]\033[25m${DEF_COLOR}\n"
