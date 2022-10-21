# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scartage <scartage@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 15:40:55 by scartage          #+#    #+#              #
#    Updated: 2022/10/21 17:29:26 by scartage         ###   ########.fr        #
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

SRCS		= main.c aux_errores.c \
			  get_next_line.c		get_next_line_utils.c get_line.c \
			  make_map.c check_map.c check_playable.c		\
			  reading_imgs_to_mini.c map_functions.c	\
			  movements.c free_all.c

INCLUDES 	= libft/libft.a minilibx_macos/libmlx.a

OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

vpath %.c sources sources/GNL

.SECONDEXPANSION:

all: make_libs	$(NAME)

make_libs:
		@make -C libft
		@make -C minilibx_macos

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)
		
$(OBJ_DIR)/%.o: %.c   $(OBJ_DIR) $(INCLUDES_H) Makefile
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJS) $(INCLUDES) -o $(NAME)

clean:
		make clean -C libft
		make clean -C minilibx_macos
		$(RM) $(OBJS)
	
fclean: clean
		make fclean -C libft
		$(RM) $(NAME)
		$(RMDIR) $(OBJ_DIR)

re: fclean all
	
.PHONY: all clean fclean re
