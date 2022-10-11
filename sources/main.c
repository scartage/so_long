/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:11:38 by scartage          #+#    #+#             */
/*   Updated: 2022/10/11 21:02:13 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Funcion para saber cuantas lineas del mapa hay con info*/
static int count_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

/*Funcion para ir rellenando el mapa (en new (mapa auxiliar)) para luego
 * devolverlo y poner la info en el mapa "real"*/
char	**push(char **array, char *str)
{
	int i;
	int x;
	char	**new;

	i = 0;
	x = count_array(array);
	new = ft_calloc(sizeof(char *),  x + 2);
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
char	**read_file(char *file)
{
	int i;
	int fd;
	char **map;
	char *line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_perror("Error: problema con el mapa\n");
	map = ft_calloc(sizeof(char *), 1);
	if (map == NULL)
		ft_perror("Error: fallo de memoria en el malloc de map\n");
	i = 0;
	while(1)
	{
		line = get_next_line(fd);
		if (i == 0 && line == NULL)
			ft_perror_map();
		if (line != NULL)
			map = push(map, line);
		else
			break;
		i++;
	}	
	close (fd);
	return (map);
}

/*Funcion encargada de revisar si la extension del archivo es correcta*/
void ft_check_ext_file(char *file)
{
	int len;

	len = ft_strlen(file);
	if (ft_strnstr(&file[len - 4], ".ber", 4) == 0)
		ft_perror("Error: extension del archivo incorrecta\n");
}

int	main(int ac, char **av)
{
	int i = 0;
	t_vars vars;

	if (ac != 2)
		ft_perror("Error: ./so_long map.ber\n");
	ft_check_ext_file(av[1]);					//revisamos extension
	vars.map = read_file(av[1]);				//llenamos el mapa
	vars.map_copy = read_file(av[1]);
	vars.height = count_array(vars.map);		//sacamos el alto
	vars.width = (ft_strlen(vars.map[0]) - 1);	//sacamos el ancho

	if (ft_check_map(&vars) == 0)
		printf("los mapas pasan los parametros\n"); //revisamos el mapa
	/*Bucle temporal, para mostrar si se lee bien el mapa*/
	printf("mapa original\n");
	while (1)
	{	
		if (vars.map[i] != NULL)
		{
			printf("%i: %s", i, vars.map[i]);
			i++;
		}
		else
			break;
	}
	printf("alto: %i, ancho: %i, coleccionables: %i\n", vars.height, vars.width, vars.col);
	
	printf("mapa copia\n");
	i = 0;
	while (1)
	{	
		if (vars.map_copy[i] != NULL)
		{
			printf("%i: %s", i, vars.map_copy[i]);
			i++;
		}
		else
			break;
	}

	printf("la posicion de P es: (%i, %i)\n", vars.px, vars.py);
	return (0);
}
