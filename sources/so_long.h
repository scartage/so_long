/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:07:23 by scartage          #+#    #+#             */
/*   Updated: 2022/10/26 21:40:17 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
#include "../minilibx_macos/mlx.h"
#include "GNL/get_next_line.h"
#include "ft_printf/ft_printf.h"
#include <stdio.h>		//para usar el perror, printf
#include <fcntl.h>		/*Para el O_RDONLY de el open*/
#include <stdlib.h>		//para usar el exit y el free

# define SIZE 50
/*Estructura para la tener diferentes variables en imgs*/
typedef struct
{
	void	*img_ptr;
	void	*data;
	int		bpp;
	int		size;
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

	int		counter;
	int		px;
	int		py;
	char	player;
	int		s_pos;		//start pos, tiene que ser 1
	int		n_pos;

	int		col;
	int		exit;

	int		col_copy;
	int		exit_copy;

	void	*mlx;
	void	*win_ptr;
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

/*Funciones para inicializar imagenes para la minilibx*/
void	reading_imgs(t_vars *vars);
void	keep_reading_imgs(t_vars *vars, int height, int width);

/*Funciones para comprobar que el mapa sea correcto (casos de error)*/
int		ft_check_map(t_vars *vars);
int		ft_no_saltos(char *line);
int		ft_check_chars(t_vars *vars);
int		ft_inside_one(t_vars *vars);
int		ft_is_rectangle(t_vars *vars);

/*para revisar que el mapa sea jugable*/
int		ft_is_playable(t_vars	*vars);
void	validate_path(t_vars *vars, int px, int py);

/*funciones varias pasa usar con el mapa y la minilibx*/
int print_game_map(t_vars *vars);
int player_movs(int key_symbol, t_vars *vars);
int which_key(int key_symbol);
int must_not_move(t_vars *vars);

/*Funciones para liberar*/
int free_memory(t_vars *vars);
void ft_clean_map_copy(t_vars *vars);
void clean_map(t_vars *vars);
#endif
