/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:45:39 by scartage          #+#    #+#             */
/*   Updated: 2022/10/10 20:26:59 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/*Funcion que revisa que no hayan dobles saltos de linea
 * se llama a la hora de leer el file
 * NO FUNCIONA, OJO*/
int ft_no_saltos(char *line)
{
	int i = 0;

	while (1)
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			return (1);
		if (line[i] == '\0')
			break;
		i++;
	}
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
	int j;

	x = 0;
	while (x < vars->height)
	{
		j = 0;
		while (j < vars->width)
		{
			if (vars->map[x][j] == 'C')
				vars->col = vars->col + 1;
			else if (vars->map[x][j] == 'E')
				vars->exit = vars->exit + 1;
			else if (vars->map[x][j] == 'P')
				vars->s_pos = vars->s_pos + 1;
			j++;
		}
		x++;
	}
	if (vars->col == 1 && vars->exit == 1 && vars->s_pos == 1)
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

int ft_check_map(t_vars *vars)
{
	/*if (ft_no_saltos(vars) == 1)
		ft_perror("Error: mapa invalido\n");*/
	if (ft_only_chars(vars) == 1)
		ft_perror("Error: mapa incorrecto, posiblemete chars no validos\n");
	if (ft_check_chars(vars) == 1)
		ft_perror("Error: solo puede haber: 1E, 1P, 1C");
	if (ft_inside_one(vars) == 1)
		ft_perror("Error: el mapa tiene que estar bordeado de 1\n");
		return (0);
}
