# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scartage <scartage@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 15:40:55 by scartage          #+#    #+#              #
#    Updated: 2022/10/28 17:52:29 by scartage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
FRAMEWORKS 	= -framework OpenGL -framework AppKit

RM 			= rm -f
RMDIR 		= rm -rf


INCLUDES_H	=	minilibx_macos/mlx.h	\
				sources/so_long.h 			\
				sources/GNL/get_next_line.h \
				sources/ft_printf/ft_printf.h

SRCS		= main.c aux_errores.c \
			  get_next_line.c		get_next_line_utils.c  \
			  make_map.c check_map.c check_playable.c		\
			  reading_imgs_to_mini.c map_functions.c	\
			  movements.c no_movements.c free_all.c		\
			  ft_printf.c ft_print_args.c ft_printf_tools.c

INCLUDES 	= libft/libft.a minilibx_macos/libmlx.a sources/ft_printf/libftprintf.a

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

vpath %.c sources sources/GNL sources/ft_printf

.SECONDEXPANSION:

all: make_libs	$(NAME)

make_libs:
		make -C libft
		@make -C minilibx_macos
		make -C sources/ft_printf

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)
		
$(OBJ_DIR)/%.o: %.c   $(OBJ_DIR) $(INCLUDES_H) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(OBJ_DIR)
		$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJS) $(INCLUDES) -o $(NAME)

clean:
		make clean -C libft
		make clean -C minilibx_macos
		make clean -C sources/ft_printf
		$(RM) $(OBJS)
	
fclean: clean
		make fclean -C libft
		make fclean -C sources/ft_printf
		$(RM) $(NAME)
		$(RMDIR) $(OBJ_DIR)

re: fclean all
	
.PHONY: all clean fclean re
