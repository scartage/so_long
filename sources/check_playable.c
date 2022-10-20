/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_playable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:02:10 by scartage          #+#    #+#             */
/*   Updated: 2022/10/18 20:22:55 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int		ft_is_playable(t_vars	*vars)
{
	vars->col_copy = 0;
	vars->exit_copy = 0;
	validate_path(vars, vars->px, vars->py);
	if (vars->col != vars->col_copy)
		return (1);
	if (vars->exit_copy != 1)
		return (1);
	else
		ft_clean_map_copy(vars);
	return (0);
}
