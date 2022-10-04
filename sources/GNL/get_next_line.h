/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:04:47 by scartage          #+#    #+#             */
/*   Updated: 2022/05/04 18:39:39 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 5000
# include <stdlib.h>
# include <unistd.h>

/* funciones/herramientas */

size_t	gnl_strlen(char *str);
char	*gnl_strchr(char *str, int c);
char	*gnl_strjoin(char *s1, char *s2);

/*funciones dentro del get para "procesar" lo que guardamos/mostramos */

char	*get_next_line(int fd);
char	*goto_read(int fd, char	*save);
char	*make_line(char			*save);
char	*save_next_line(char	*save);

/*funcion especialmente disenada para el fdf*/

char	*get_line(int fd);

#endif
