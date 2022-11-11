/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:20:29 by scartage          #+#    #+#             */
/*   Updated: 2022/11/11 21:59:59 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*Funcion para saber cuantas lineas del mapa hay con info*/
int	count_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

/*Funcion para ir rellenando el mapa (en new (mapa auxiliar)) para luego
 * devolverlo y poner la info en el mapa "real"*/
char	**push(char **array, char *str)
{
	int		i;
	int		x;
	char	**new;

	i = 0;
	x = count_array(array);
	new = ft_calloc(sizeof(char *), x + 2);
	if (new == NULL)
		ft_perror("Error: fallo de memoria en map aux (new)\n");
	while (i < x)
	{
		new[i] = array[i];
		i++;
	}
	new[i] = str;
	free(array);
	return (new);
}

/*Funcion encargada de revisar si la extension del archivo es correcta*/
void	ft_check_ext_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strnstr(&file[len - 4], ".ber", 4) == 0)
		ft_perror("Error: extension del archivo incorrecta\n");
}

/*funcion para leer el mapa y guardalor en vars->map*/
char	**read_file(char *file)
{
	int		i;
	int		fd;
	char	**map;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_perror("Error: problema con el mapa\n");
	map = ft_calloc(sizeof(char *), 1);
	if (map == NULL)
		ft_perror("Error: fallo de memoria en el malloc de map\n");
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (i == 0 && line == NULL)
			ft_perror_map();
		if (line != NULL)
			map = push(map, line);
		else
			break ;
		i++;
	}
	close (fd);
	return (map);
}
