/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:07:23 by scartage          #+#    #+#             */
/*   Updated: 2022/11/11 21:55:37 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include "GNL/get_next_line.h"
# include "ft_printf/ft_printf.h"
//# include <stdio.h>		//para usar el perror, printf
# include <fcntl.h>		/*Para el O_RDONLY de el open*/
# include <stdlib.h>		//para usar el exit y el free

# define SIZE 50

/*OJO QUE TENEMOS POR AHI UN .TXT QUE TENEMOS QUE BORRAR O MOVER*/
/*Estructura para la tener diferentes variables en imgs*/

/*OJO arreglar el que cuando el jugador este en la salida aparzca
 * el mensaje de you won sin que tenga que moverse*/
typedef struct s_truct
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
typedef struct s_vars
{
	char	**map;
	char	**map_copy;

	int		height;
	int		width;

	int		counter;
	int		px;
	int		py;
	char	player;
	int		s_pos;
	int		n_pos;

	int		exit_px;
	int		exit_py;
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
int		ft_perror(char	*str);
int		count_array(char **array);
void	ft_perror_map(void);

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
void	get_exit_data(int y, int x, t_vars *vars);
void	ft_check_ext_file(char *file);
/*para revisar que el mapa sea jugable*/
int		ft_is_playable(t_vars	*vars);
void	validate_path(t_vars *vars, int px, int py);

/*funciones varias pasa usar con el mapa y la minilibx*/
int		print_game_map(t_vars *vars);
int		player_movs(int key_symbol, t_vars *vars);
int		which_key(int key_symbol);
int		must_not_move(t_vars *vars);

/*Funciones para liberar*/
int		free_memory(t_vars *vars);
void	ft_clean_map_copy(t_vars *vars);
void	clean_map(t_vars *vars);
#endif
