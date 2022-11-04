# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scartage <scartage@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 15:40:55 by scartage          #+#    #+#              #
#    Updated: 2022/11/03 19:19:56 by scartage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= so_long
NAME_bonus 	= so_long_bonus
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
FRAMEWORKS 	= -framework OpenGL -framework AppKit

RM 			= rm -f
RMDIR 		= rm -rf


INCLUDES_H	=	minilibx_macos/mlx.h	\
				sources/so_long.h 			\
				so_bonus/GNL/get_next_line.h \
				so_bonus/ft_printf/ft_printf.h \
				sources/GNL/get_next_line.h \
				sources/ft_printf/ft_printf.h

SRCS		= main.c aux_errores.c \
			  get_next_line.c		get_next_line_utils.c  \
			  make_map.c check_map.c check_playable.c		\
			  reading_imgs_to_mini.c map_functions.c	\
			  movements.c no_movements.c free_all.c		\
			  ft_printf.c ft_print_args.c ft_printf_tools.c

SRCS_bonus = main_bonus.c aux_errores_bonus.c get_next_line.c \
			 get_next_line_utils.c make_map_bonus.c check_map_bonus.c \
			 check_playable_bonus.c reading_imgs_to_mini_bonus.c \
			 map_functions_bonus.c movements_bonus.c no_movements_bonus.c\
			 free_all_bonus.c ft_printf.c ft_print_args.c ft_printf_tools.c

INCLUDES 	= libft/libft.a minilibx_macos/libmlx.a sources/ft_printf/libftprintf.a
INC_bonus	= libft/libft.a minilibx_macos/libmlx.a so_bonus/ft_printf/libftprintf.a


OBJ_DIR		= obj
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_bonus	= $(addprefix $(OBJ_DIR)/, $(SRCS_bonus:.c=.o))


vpath %.c sources  sources/GNL sources/ft_printf so_bonus so_bonus/GNL so_bonus/ft_printf
.SECONDEXPANSION:

all: make_libs	$(NAME)

make_libs:
		make -C libft
		@make -C minilibx_macos
		make -C sources/ft_printf
		make -C so_bonus/ft_printf

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)
		
$(OBJ_DIR)/%.o: %.c   $(OBJ_DIR) $(INCLUDES_H) Makefile
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(OBJ_DIR)
		$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJS) $(INCLUDES) -o $(NAME)

bonus: $(OBJS_bonus) $(OBJS_DIR) make_libs
		$(CC) $(CFLAGS) $(FRAMEWORKS) $(OBJS_bonus) $(INC_bonus) -o $(NAME_bonus)

clean:
		make clean -C libft
		make clean -C minilibx_macos
		make clean -C sources/ft_printf
		make clean -C so_bonus/ft_printf
		$(RM) $(OBJS)
	
fclean: clean
		make fclean -C libft
		make fclean -C sources/ft_printf
		make fclean -C so_bonus/ft_printf
		$(RM) $(NAME)
		$(RM) $(NAME_bonus)
		$(RMDIR) $(OBJ_DIR)

re: fclean all
	
.PHONY: all clean fclean re bonus
