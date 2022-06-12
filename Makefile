CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
SL		=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
DBG		=	-g3 -fsanitize=address -fsanitize=leak
CI		=	-I include/

AR		=	ar rcs
RM		=	rm -rf

NAME	=	so_long
LIBFT	=	libft/libft.a
LIBMLX	=	mlx/libmlx.a

SRCS	=	srcs/build_map_and_check_tile.c \
			srcs/check_map_and_wall_err.c \
			srcs/err.c \
			srcs/game_loop.c \
			srcs/get_next_line.c \
			srcs/get_next_line_utils.c \
			srcs/print_move_count.c \
			srcs/so_long.c \
			srcs/utils.c

HEAD	=	include/so_long.h \
			include/key.h \
			include/get_next_line.h

all			:	$(NAME)

$(NAME)	:	$(SRCS) $(HEAD) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $(CI) $(SRCS) $(LIBFT) $(LIBMLX) $(DBG) $(SL) -o $(NAME)

$(LIBFT)	:
	make -C libft/

$(LIBMLX)	:
	make -C mlx/

clean		:
	$(RM)

fclean		:	clean
	$(RM) $(NAME)
	make fclean -C libft/
	make clean -C mlx/

re			:	fclean all

.PHONY		:	all clean fclean re
