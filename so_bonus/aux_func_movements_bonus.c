/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func_movements_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:27:09 by scartage          #+#    #+#             */
/*   Updated: 2022/11/11 22:09:31 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*Funcion del movements*/
int	check_if_finished(t_vars *vars)
{
	if (is_finished(vars) == 0)
	{
		if (vars->alive == 0)
			mlx_string_put(vars->mlx, vars->win_ptr, vars->px + 10, \
				vars->py + 5, 0x0000FF00, "YOU DIED!!!");
		else
			mlx_string_put(vars->mlx, vars->win_ptr, vars->px + 10, \
				vars->py + 5, 0x0000FF00, "YOU WON!!!");
		return (1);
	}
	return (0);
}

/*Con esta funcion evaluamos que la posicion donde estamos
 * no sea la misma que la de los "enemigos"
 * en caso de que si la variable "alive" pasa a ser 0,
 * indicando que el jugador ha muerto*/
int	check_if_enemy(t_vars *vars, int x, int y)
{
	int	x_b;
	int	y_b;
	int	i;

	i = 0;
	while (i < vars->hm_enemy)
	{
		x_b = vars->enemy[i].py_b;
		y_b = vars->enemy[i].px_b;
		if (x == y_b && y == x_b)
		{
			vars->alive = 0;
			is_finished(vars);
		}
		i++;
	}
	return (0);
}
