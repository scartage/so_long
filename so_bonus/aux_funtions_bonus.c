/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funtions_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:55:47 by scartage          #+#    #+#             */
/*   Updated: 2022/11/11 22:12:20 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*Funciones auxiliares de print_map*/
void	get_exit_data(int y, int x, t_vars *vars)
{
	vars->exit = vars->exit + 1;
	vars->exit_px = y;
	vars->exit_py = x;
}

void	get_enemy_data(int y, int x, t_vars *vars)
{
	int	i;

	i = vars->hm_enemy;
	if (vars->enemy[i].px_b == 0)
	{
		vars->enemy[i].px_b = y;
		vars->enemy[i].py_b = x;
	}
	vars->hm_enemy = vars->hm_enemy + 1;
}

void	initializing_vars(t_vars *vars)
{
	vars->col = 0;
	vars->s_pos = 0;
	vars->hm_enemy = 0;
	vars->exit = 0;
}

int	checking_if_correct(t_vars *vars)
{
	if (vars->exit == 1 && vars->s_pos == 1 && \
		vars->col > 0 && vars->hm_enemy > 0)
		return (0);
	else
		return (1);
}

void	get_player_data(int y, int x, t_vars *vars)
{
	vars->s_pos = vars->s_pos + 1;
	vars->px = y;
	vars->py = x;
}
