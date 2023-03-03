# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbenaiss <rbenaiss@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 20:43:25 by rbenaiss          #+#    #+#              #
#    Updated: 2023/03/03 23:01:35 by rbenaiss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAMEC = client
NAMES = server
PRINTF = libftprintf.a
SRCC_FILES =	client.c
SRCS_FILES =	server.c
SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C printf
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) printf/$(PRINTF) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -C printf
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) printf/$(PRINTF) -o $(NAMES)

clean :
		@make clean -C printf
		${RM} ${OBJC}
		${RM} ${OBJS}

fclean : clean
		@make fclean -C printf
		${RM} $(NAMEC)
		${RM} $(NAMES)
		${RM} $(PRINTF)

re : fclean all

.PHONY:		all bonus clean fclean re