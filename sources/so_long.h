/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:07:23 by scartage          #+#    #+#             */
/*   Updated: 2022/10/10 19:37:34 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"
#include "GNL/get_next_line.h"
#include <stdio.h>		//para usar el perror, printf
#include <fcntl.h>		/*Para el O_RDONLY de el open*/
#include <stdlib.h>		//para usar el exit


//de momento vamos a rellenar el mapa con lo que nos pasen
typedef struct
{
	char	**map;
	int		height;
	int		width;
	int		col;
	int		exit;
	int		s_pos;
}	t_vars;

/*Funcion auxiliar para casos de errores
 * Esta en aux_errores.c	*/
int ft_perror(char	*str);

/*Funciones*/
char	**read_file(char *in_map);
char	**push(char **array, char *str);

int		ft_check_map(t_vars *vars);
int		ft_no_saltos(char *line);
int		ft_check_chars(t_vars *vars);
int		ft_inside_one(t_vars *vars);
#endif
