/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:03:54 by scartage          #+#    #+#             */
/*   Updated: 2022/10/21 17:21:47 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void destroy_img(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win_ptr);
	exit (0);
}

void ft_clean_map(t_vars *vars)
{
	int alto;

	alto = vars->height;
	if (vars->map)
	{
		free(vars->map[alto]);
		while (alto > 0)
		{
			alto--;
			free(vars->map[alto]);
		}
		free(vars->map);
	}
}

void ft_clean_map_copy(t_vars *vars)
{
	int i;
	int alto;

	i = 0;
	alto = vars->height + 1;
	while (i < alto)
	{
		if (vars->map_copy[i])
			free(vars->map_copy[i]);
		i++;
	}
	free(vars->map_copy);
	vars->map_copy = NULL;
}

/*Funcion auxiliar para limpiar segun lo que exista
 * si existe un mapa, lo liberamos.
 * si existe un copy lo liberamos.
 * liberamos el puntero de las imagenes
 * y por ultimo destruimos la window*/
int free_memory(t_vars *vars)
{
	if (vars->map)
		ft_clean_map(vars);
	if (vars->map_copy)
		ft_clean_map_copy(vars);
	if (vars->imgs)
		free(vars->imgs);
	destroy_img(vars);
	return (0);
}
