NAME		= so_long
INC			= include
INC		= -I include
LIBFT		= libft
PRINTF		= printf
MINILIBX	= mlx
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -rf
LINKS	    = -I /usr/X11/include -L /usr/X11/lib -lmlx \
		      -framework OpenGL -framework AppKit
SRC_DIR		= 	sources/
MAND_FILES	=	mario map window utils keyboard
SRC_FILES	=	$(addprefix $(SRC_DIR), $(MAND_FILES))
SRC 		= 	$(addsuffix .c, $(SRC_FILES))
OBJ 		= 	$(addsuffix .o, $(SRC_FILES))


all:		$(NAME)

$(NAME):	$(OBJ)
			@make -s -C $(LIBFT)
			@make -s -C $(PRINTF)
			$(CC) $(CFLAGS) $(OBJ) $(HEADER) $(LIBFT)/libft.a  $(PRINTF)/libftprintf.a $(LINKS) -o $(NAME)


clean:
			@make clean -C $(LIBFT)
			@make clean -C $(PRINTF)
			$(RM) $(OBJ)
fclean:		clean
			@$(RM) $(NAME)
			@$(RM) $(LIBFT)/libft.a
			@$(RM) $(PRINTF)/libftprintf.a

re:			fclean all

.PHONY:		all clean fclean re 