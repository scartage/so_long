/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:07:23 by scartage          #+#    #+#             */
/*   Updated: 2022/10/17 19:49:34 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"
#include "GNL/get_next_line.h"
#include <stdio.h>		//para usar el perror, printf
#include <fcntl.h>		/*Para el O_RDONLY de el open*/
#include <stdlib.h>		//para usar el exit y el free

typedef struct
{
	void	*img_ptr;
	void	*data;
	int		bbp;
	int		length;
	int		endian;
}	t_img;

/*estructura donde tenemos varias variables para usar el programa
 * hay un mapa original, que es el que se usa, una copia para revisar
 * si el mapa es jugable*/
typedef struct
{
	char	**map;
	char	**map_copy;

	int		height;
	int		width;
	
	int		px;
	int		py;
	int		s_pos;

	int		col;
	int		exit;

	int		col_copy;
	int		exit_copy;

	void	*mlx
	void	*win_ptr
	t_img	*imgs;
}	t_vars;

/*Funcion auxiliar para casos de errores
 * ft_perror es para errores generales,
 * ft_perror_map para mapas invalidos*/
int ft_perror(char	*str);
void ft_perror_map();
int	count_array(char **array);

/*Funciones para leer el file y crear el mapa*/
char	**read_file(char *in_map);
char	**push(char **array, char *str);

/*Funciones para comprobar que el mapa sea correcto*/
int		ft_check_map(t_vars *vars);
int		ft_no_saltos(char *line);
int		ft_check_chars(t_vars *vars);
int		ft_inside_one(t_vars *vars);
int		ft_is_rectangle(t_vars *vars);

int		ft_is_playable(t_vars	*vars);
void	validate_path(t_vars *vars, int px, int py);
#endif
