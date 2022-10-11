/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:45:39 by scartage          #+#    #+#             */
/*   Updated: 2022/10/11 20:49:41 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_is_rectangle(t_vars *vars)
{
	size_t	size;
	int		i;

	size = vars->width;
	i = 0;
	while (i < vars->height)
	{
		if (size != ft_strlen(vars->map[i]) - 1)
			return (1);
		i++;
	}
	if (vars->height == vars->width)
		return (1);
	return (0);
}


/*Para revisar que solo hayan caracteres validos*/
int ft_only_chars(t_vars *vars)
{
	int x;
	int j;

	x = 0;
	while (x < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			if (vars->map[x][j] != '1' && vars->map[x][j] != '0'
					&& vars->map[x][j] != 'C'
					&& vars->map[x][j] != 'E'
					&& vars->map[x][j] != 'P'
					&& vars->map[x][j] != '\0'
					&& vars->map[x][j] != '\n')
				return (1);
			j++;
		}
		x++;
	}
	return (0);
}

/*Funcion para revisar que solo haya 1 EPC*/
int	ft_check_chars(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->map[y][x] == 'C')
				vars->col = vars->col + 1;
			else if (vars->map[y][x] == 'E')
				vars->exit = vars->exit + 1;
			else if (vars->map[y][x] == 'P')
			{
				vars->s_pos = vars->s_pos + 1;
				vars->px = x;
				vars->py = y;
			}
			x++;
		}
		y++;
	}
	if (vars->exit == 1 && vars->s_pos == 1)
		return (0);
	else
		return (1);
}

/*Funcion para revisar que el mapa esta bordeado correctamente*/
int ft_inside_one(t_vars *vars)
{
	int x;
	int j;

	x = 0;
	while (x < vars->width)		//ancho
	{
		if (vars->map[0][x] != '1' || vars->map[vars->height - 1][x] != '1')
			return (1);
		x++;
	}
	if (x != vars->width)
		return (1);

	j = 0;
	while (j < vars->height)
	{
		if (vars->map[j][0] != '1' || vars->map[j][vars->width - 1] != '1')
			return (1);
		j++;
	}
	if (j != vars->height)
		return (1);
	return (0);
}

/*Funcion que da paso a otras funciones para revisar casos de error del mapa
 * el primero revisa que solo hayan los caracteres obligatiorios {0,1,C,E,P}
 * la segunda revisa que solo haya 1E, 1C, 1P
 * la tercera revisa que el mapa este cerrados por '1'*/
int ft_check_map(t_vars *vars)
{	
	if (ft_only_chars(vars) == 1)
		ft_perror_map();
	if (ft_check_chars(vars) == 1)
		ft_perror_map();
	if (ft_inside_one(vars) == 1)
		ft_perror("Error: el mapa tiene que estar bordeado de 1\n");
	if (ft_is_rectangle(vars) == 1)
		ft_perror("Error: el mapa tiene que ser rectangular\n");
	if (ft_is_playable(vars) == 1)
		ft_perror("Error: el mapa no es jugable\n");
		return (0);
}
