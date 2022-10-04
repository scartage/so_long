/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:11:38 by scartage          #+#    #+#             */
/*   Updated: 2022/10/04 20:56:08 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
static int count_array(char **array)
{
	int i;

	i = 0;
	while(array[i] != NULL)
		i++;
	return (i);
}

char	**push(char **array, char *str)
{
	int i;
	int x;
	char	**new;

	i = 0;
	x = count_array(array);
	new = malloc(sizeof(char *) * x + 2);
	if (new == NULL)
		ft_perror("Error: fallo de memoria en map aux (new)\n");
	while (i < x)
	{
		new[i] = array[i];
		i++;
	}
	new[i] = str;
	free(array);
	return(new);
}

/*funcion para leer el mapa y guardalor en vars->map*/
char	**read_map(char *file)
{
	int fd;
	char **map;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_perror("Error: problema con el mapa\n");
	map = malloc(sizeof(char *) * 1);
	if (map == NULL)
		ft_perror("Error: fallo de memoria en el malloc de map\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
			map = push(map, line);
		else
			break;
	}
	close (fd);
	return (map);
}

int	main(int ac, char **av)
{
	int i;
	int j;
	t_vars vars;

	if (ac != 2)
		ft_perror("Error: ./so_long mapa.ber\n");
	//lo primero es darle valor a esta variable
	vars.map = read_map(av[1]);
	
	i = 0;
	while (i)
	{
		j = 0;
		while (j)
		{
			printf("%3d", vars.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
