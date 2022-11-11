/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:31:10 by scartage          #+#    #+#             */
/*   Updated: 2022/11/11 21:07:00 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Se mira que hacia arriba (la W va para arriba) no hayan paredes o salidas, 
 * en caso de que haya un coleccionable lo "toma"*/
static int	must_not_w(t_vars *vars)
{
	if (vars->map[vars->px - 1][vars->py] == '1')
		return (-1);
	else if (vars->map[vars->px - 1][vars->py] == 'E')
	{
		if (vars->col != 0)
		{
			mlx_string_put(vars->mlx, vars->win_ptr, vars->px + 5, \
				vars->py + 10, 0x0000FF00, "take first all the collectibles");
			return (-1);
		}
	}
	else if (vars->map[vars->px - 1][vars->py] == 'C')
	{
		vars->col--;
		return (0);
	}
	return (0);
}

static int	must_not_s(t_vars *vars)
{
	if (vars->map[vars->px + 1][vars->py] == '1')
		return (-1);
	else if (vars->map[vars->px + 1][vars->py] == 'E')
	{
		if (vars->col != 0)
		{
			mlx_string_put(vars->mlx, vars->win_ptr, vars->px + 5, \
				vars->py + 10, 0x0000FF00, "take first all the collectibles");
			return (-1);
		}
	}
	else if (vars->map[vars->px + 1][vars->py] == 'C')
	{
		vars->col--;
		return (0);
	}
	return (0);
}

static int	must_not_a(t_vars *vars)
{
	if (vars->map[vars->px][vars->py - 1] == '1')
		return (-1);
	else if (vars->map[vars->px][vars->py - 1] == 'E')
	{
		if (vars->col != 0)
		{
			mlx_string_put(vars->mlx, vars->win_ptr, vars->px + 5, \
				vars->py + 10, 0x0000FF00, "take first all the collectibles");
			return (-1);
		}
	}
	else if (vars->map[vars->px][vars->py - 1] == 'C')
	{
		vars->col--;
		return (0);
	}
	return (0);
}

static int	must_not_d(t_vars *vars)
{
	if (vars->map[vars->px][vars->py + 1] == '1')
		return (-1);
	else if (vars->map[vars->px][vars->py + 1] == 'E')
	{
		if (vars->col != 0)
		{
			mlx_string_put(vars->mlx, vars->win_ptr, vars->px + 5, \
				vars->py + 10, 0x0000FF00, "take first all the collectibles");
			return (-1);
		}
	}
	else if (vars->map[vars->px][vars->py + 1] == 'C')
	{
		vars->col--;
		return (0);
	}
	return (0);
}

/*Comprobamos casos de cada letra para saber si se puede mover,
 * NO puede pasar paredes y tampoco puede estar "cerca" de la salida
 * en caso que (segun baje, suba o se mueva para los lados) haya un coleccionable
 * lo "tomara" y se le restaran colecionables a la variable vars->col*/
int	must_not_move(t_vars *vars)
{
	if (vars->n_pos == 'W')
	{
		if (must_not_w(vars) == -1)
			return (-1);
	}
	else if (vars->n_pos == 'S')
	{
		if (must_not_s(vars) == -1)
			return (-1);
	}
	else if (vars->n_pos == 'A')
	{
		if (must_not_a(vars) == -1)
			return (-1);
	}
	else if (vars->n_pos == 'D')
	{
		if (must_not_d(vars) == -1)
			return (-1);
	}
	return (0);
}
