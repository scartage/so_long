/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:20:09 by scartage          #+#    #+#             */
/*   Updated: 2022/11/04 19:51:36 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
/*Funcion que recorre el mapa para ver si es rectangular
 * se recorre por lineas de alto, comparando que size (el ancho) sea igual
 * a la forma en la que se saca el ancho. Si en algun momento es diferente es porque
 * hay un error. El ancho NO puede ser igual alto, porque seria un cuadrado.*/
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

static void get_exit_data(int y, int x, t_vars *vars)
{
	vars->exit = vars->exit + 1;
	vars->exit_px = y;
	vars->exit_py = x;
}

void get_enemy_data(int y, int x, t_vars *vars)
{
	int i;

	i = vars->hm_enemy;	//primera vez seria 0
	if (vars->enemy[i].px_b == 0)
	{
		vars->enemy[i].px_b = y;
		vars->enemy[i].py_b = x;
	}
	vars->hm_enemy = vars->hm_enemy + 1;

	ft_printf("there are: %i enemys\n", vars->hm_enemy);
	ft_printf("in this pos: x:%i, y:%i, %p\n", vars->enemy[i].py_b, vars->enemy[i].px_b, vars->enemy[i]);
}

/*Funcion para revisar que solo haya 1 Exit y 1 posicion inicial*/
int	ft_check_chars(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	vars->col = 0;
	vars->s_pos = 0;
	vars->hm_enemy = 0;
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
			{
				vars->s_pos = vars->s_pos + 1;
				vars->px = y;
				vars->py = x;
			}
			x++;
		}
		y++;
	}
	if (vars->exit == 1 && vars->s_pos == 1 && vars->col > 1 && vars->hm_enemy > 0)
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
	if (x != vars->width)	//la x tiene que ser igual al ancho
		return (1);
	j = 0;
	while (j < vars->height)
	{
		if (vars->map[j][0] != '1' || vars->map[j][vars->width - 1] != '1')
			return (1);
		j++;
	}
	if (j != vars->height)	//la j tiene que ser igual alto
		return (1);
	return (0);
}

/*Funcion que da paso a otras funciones para revisar casos de error del mapa
 * el primero revisa que solo hayan los caracteres obligatiorios {0,1,C,E,P}
 * la segunda revisa que solo haya 1E, 1C, 1P
 * la tercera revisa que el mapa este cerrados por '1'*/
int ft_check_map(t_vars *vars)
{	
	vars->height = count_array(vars->map);		//sacamos el alto
	vars->width = (ft_strlen(vars->map[0]) - 1);	//sacamos el ancho``

	vars->enemy = malloc(sizeof(t_bonus) * 5);
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
