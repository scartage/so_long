/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_funtions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 21:26:54 by scartage          #+#    #+#             */
/*   Updated: 2022/10/21 15:53:12 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Recuerda: en las matrices de array van (y: columnas) (x: filas)*/
/*Funcion para imprimir a el jugador segun donde este y como este mirando (AWSD)*/
void print_map_player(t_vars *vars, int x, int y)
{
	/*esto hay que revisar que este en el orden correcto*/
	vars->px = x;
	vars->py = y;
	/*arriba*/
	if (vars->s_pos == 'W')
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, vars->imgs[3].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->s_pos == 'S')
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, vars->imgs[5].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->s_pos == 'A')
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, vars->imgs[6].img_ptr, (y * SIZE), (x * SIZE));
	else
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, vars->imgs[7].img_ptr, (y * SIZE), (x * SIZE));
}

/*Funcion auxiliar para poner seguir poniendo imagenes segun el mapa que nos pasen*/
void print_more_map(t_vars *vars, int x, int y)
{
	if (vars->map[x][y] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, vars->imgs[1].img_ptr, (y * SIZE), (x * SIZE));
	else if (vars->map[x][y] == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win_ptr, vars->imgs[2].img_ptr, (y * SIZE), (x * SIZE));
		vars->col++;
	}
}

/*esta funcion nos muestra por pantalla las imagenes para crear el juego*/
int print_game_map(t_vars *vars)
{
	int x;
	int y;

	x = 0;
	y = 0;
	vars->col = 0;
	while(vars->map[x])
	{
		y = 0;
		while (vars->map[x][y])
		{
			if (vars->map[x][y] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win_ptr, vars->imgs[0].img_ptr, (y * SIZE), (x * SIZE));
			else if (vars->map[x][y] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win_ptr, vars->imgs[4].img_ptr, (y * SIZE), (x * SIZE));
			else if (vars->map[x][y] == 'P')
				print_map_player(vars, x, y);	//para printar al jugador, dependiendo su orientacion
			print_more_map(vars, x, y); //Para printar mas elementos del mapa
			y++;
		}
		x++;
	}
	return (0);
}
