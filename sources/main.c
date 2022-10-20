/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:11:38 by scartage          #+#    #+#             */
/*   Updated: 2022/10/18 20:31:59 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars vars;

	if (ac != 2)
		ft_perror("Error: ./so_long map.ber\n");
	vars.map = read_file(av[1]);				//llenamos el mapa_org
	vars.map_copy = read_file(av[1]);			//llenamos map_copy

	if (ft_check_map(&vars) == 0)
		printf("los mapas pasan los parametros\n"); //revisamos el mapa
	vars.mlx = mlx_init();
	reading_imgs(&vars);

	vars.win_ptr = mlx_new_window(vars.mlx, vars.width * SIZE, vars.height * SIZE, "don't panic, it's just so_long");
	mlx_loop(vars.mlx);
	return (0);
}
