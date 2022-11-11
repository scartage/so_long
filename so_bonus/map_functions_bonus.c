/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:22:47 by scartage          #+#    #+#             */
/*   Updated: 2022/11/11 22:55:57 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*Recuerda: en las matrices de array van (y: columnas) (x: filas)*/
/*Funcion para imprimir a el jugador segun donde este 
 * y como este mirando (AWSD)*/
void	print_map_player(t_vars *vars, int x, int y)
{
	vars->px = x;
	vars->py = y;
	if (vars->player == 'W')
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[3].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->player == 'S')
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[5].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->player == 'A')
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[6].img_ptr, (y * SIZE), (x * SIZE));
	else
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[7].img_ptr, (y * SIZE), (x * SIZE));
}

void	print_map_enemys(t_vars *vars, int x, int y)
{
	if (vars->frames == 0)
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[13].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->frames == 15)
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[14].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->frames == 30)
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[15].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->frames == 45)
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[16].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->frames == 65)
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[17].img_ptr, (y * SIZE), (x * SIZE));
}

void	print_map_exit(t_vars *vars, int x, int y)
{
	if (vars->frames == 0)
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[4].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->frames == 20)
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[9].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->frames == 40)
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[10].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->frames == 60)
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[11].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->frames == 80)
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[12].img_ptr, (y * SIZE), (x * SIZE));
}

/*Funcion auxiliar para poner seguir poniendo imagenes 
 * segun el mapa que nos pasen*/
void	print_more_map(t_vars *vars, int x, int y)
{
	if (vars->map[x][y] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[1].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->map[x][y] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
			vars->imgs[2].img_ptr, (y * SIZE), (x * SIZE));
	}
	else if (vars->map[x][y] == 'X')
		print_map_enemys(vars, x, y);
}

/*esta funcion nos muestra por pantalla las imagenes
 * la ventana para crear el juego*/
int	print_game_map(t_vars *vars)
{
	int		x;
	int		y;

	x = 0;
	while (vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win_ptr, \
					vars->imgs[0].img_ptr, (y * SIZE), (x * SIZE));
			else if (vars->map[x][y] == 'E')
				print_map_exit(vars, x, y);
			else if (vars->map[x][y] == 'P')
				print_map_player(vars, x, y);
			print_more_map(vars, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
