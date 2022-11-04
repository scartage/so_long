/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playable_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:22:01 by scartage          #+#    #+#             */
/*   Updated: 2022/11/03 18:22:04 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*Consiste en recorrer el mapa desde la posicion P, donde vayamos pasando ponemos un 1
 * donde haya un 1 no se puede pasar, la idea es ir recogiendo coleccionables*/
void	validate_path(t_vars *vars, int px, int py)
{
	if (vars->map_copy[px][py] == '1')
		return ;
	if (vars->map_copy[px][py] == 'C')
		vars->col_copy++;
	if (vars->map_copy[px][py] == 'E')
	{
		vars->exit_copy++;
		vars->map_copy[px][py] = '1';
		return ;
	}
	vars->map_copy[px][py] = '1';
	validate_path(vars, px + 1, py);	
	validate_path(vars, px - 1, py);
	validate_path(vars, px, py - 1);	
	validate_path(vars, px, py + 1);
}

/*la copia del mapa con la que comprobamos si es jugable no se libera hasta el final
 * se comprueba comparando cuantos coleccionables hay en el mapa real y la copia
 * y viendo que solo haya una salida*/
int		ft_is_playable(t_vars	*vars)
{
	vars->col_copy = 0;
	vars->exit_copy = 0;
	validate_path(vars, vars->px, vars->py);
	if (vars->col != vars->col_copy)
		return (1);
	if (vars->exit_copy != 1)
		return (1);
	return (0);
}
