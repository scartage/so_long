/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:20:09 by scartage          #+#    #+#             */
/*   Updated: 2022/11/11 22:50:25 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
/* Funcion que recorre el mapa para ver si es rectangular*/
/* se recorre por lineas de alto, comparando que size (el ancho) sea igual*/
/* a la forma en la que se saca el ancho. Si en 
 * algun momento es diferente es porque*/
/* hay un error. El ancho NO puede ser igual alto, porque seria un cuadrado.*/
int	ft_is_rectangle(t_vars *vars)
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
int	ft_only_chars(t_vars *vars)
{
	int	x;
	int	j;

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
					&& vars->map[x][j] != 'X'
					&& vars->map[x][j] != '\0'
					&& vars->map[x][j] != '\n')
				return (1);
			j++;
		}
		x++;
	}
	return (0);
}

/*Funcion para revisar que solo haya 1 Exit y 1 posicion inicial*/
int	ft_check_chars(t_vars *vars)
{
	int	x;
	int	y;

	initializing_vars(vars);
	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->map[y][x] == 'C')
				vars->col = vars->col + 1;
			else if (vars->map[y][x] == 'E')
				get_exit_data(y, x, vars);
			else if (vars->map[y][x] == 'X')
				get_enemy_data(y, x, vars);
			else if (vars->map[y][x] == 'P')
				get_player_data(y, x, vars);
			x++;
		}
		y++;
	}
	if (checking_if_correct(vars) == 1)
		return (1);
	return (0);
}

/*Funcion para revisar que el mapa esta bordeado correctamente*/
int	ft_inside_one(t_vars *vars)
{
	int	x;
	int	j;

	x = 0;
	while (x < vars->width)
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
int	ft_check_map(t_vars *vars)
{
	vars->col = 0;
	vars->height = count_array(vars->map);
	vars->width = (ft_strlen(vars->map[0]) - 1);
	vars->enemy = ft_calloc(sizeof(t_bonus), 10);
	if (vars->enemy == NULL)
		ft_perror("Error: fallo de memoria malloc en get_enemy_data");
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
