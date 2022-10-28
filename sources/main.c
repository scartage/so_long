/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:11:38 by scartage          #+#    #+#             */
/*   Updated: 2022/10/28 20:14:05 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>
int	main(int ac, char **av)
{
	t_vars vars;

	if (ac != 2)
		ft_perror("Error: ./so_long map.ber\n");
	vars.map = read_file(av[1]);				//llenamos el mapa_org
	vars.map_copy = read_file(av[1]);			//llenamos map_copy

	if (ft_check_map(&vars) == 0)
		ft_printf("el mapa pasa los parametros\n"); //revisamos el mapa
	vars.mlx = mlx_init();
	reading_imgs(&vars);
	vars.win_ptr = mlx_new_window(vars.mlx, vars.width * SIZE, vars.height * SIZE , "don't panic, it's just so_long");
	print_game_map(&vars);

	vars.counter = 0;
	mlx_hook(vars.win_ptr, 2, 0, player_movs, &vars);	//este evento se encarga de escuchar que se pulse a key
	mlx_hook(vars.win_ptr, 17, 0, free_memory, &vars);	//este evento se encarga de cerrar si se aprieta la (x)

	mlx_loop(vars.mlx);
	free_memory(&vars);	//si no se llega a cerrar con la (x) el programa se sale despues de cerrar loop (movs)*/
	return (0);
}
