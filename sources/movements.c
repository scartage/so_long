/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:27:36 by scartage          #+#    #+#             */
/*   Updated: 2022/10/21 17:48:07 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int which_key(int key_symbol)
{
	if (key_symbol == 13 || key_symbol == 126)
		return ('w');
	else if (key_symbol == 1 || key_symbol == 125)
		return ('s');
	else if (key_symbol == 0 || key_symbol == 123 )
		return ('a');
	else if (key_symbol == 2 || key_symbol == 124)
		return ('d');
	else if (key_symbol == 53)
		return (-1);
	return (0);
}

int player_movs(int key_symbol, t_vars *vars)
{
	//printf("the key:%i", key_symbol);
	vars->n_pos = which_key(key_symbol);
	if (vars->n_pos < 0)
		free_memory(vars);
	printf("tecla: %c\n", vars->n_pos);

	return (0);
}
