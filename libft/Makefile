# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scartage <scartage@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 15:11:31 by scartage          #+#    #+#              #
#    Updated: 2022/07/07 17:10:53 by scartage         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC = gcc
CFLAGS	= -Wall -Wextra -Werror

INCLUDES = libft.h

SRCS	 = 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
			ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
			ft_memmove.c ft_memset.c ft_strncmp.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strrchr.c ft_strchr.c ft_tolower.c ft_toupper.c \
			ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c	\
			ft_strtrim.c ft_split.c  ft_itoa.c ft_strmapi.c ft_striteri.c	\
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c	\
			ft_counting_words.c ft_check_atoi.c ft_strcmp.c ft_strequal.c

BNUS	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
			ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c 		\
			ft_lstmap.c

ODIR	=	obj_libft
OBJS	= $(addprefix $(ODIR)/, $(SRCS:.c=.o))

OBJBNS	= ${BNUS:.c=.o}

RM		= rm -f
RMDIR 	= rm -rf
vpath %.c src

.SECONDEXPANSION:

all:		${NAME}
		
$(ODIR)/%.o: src/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}:	$(ODIR) ${OBJS} ${INCLUDES}
			ar rc ${NAME} ${OBJS}

bonus:		${OBJBNS} ${OBJS}
			ar rc ${NAME} ${OBJS} ${OBJBNS}

clean:
			${RM} ${OBJS} ${OBJBNS}
		    $(RMDIR) ${ODIR}

fclean:		clean
			${RM} ${NAME} 

re:			fclean all

$(ODIR):
	mkdir -p $(ODIR)

.PHONY:		all clean fclean re bonus
