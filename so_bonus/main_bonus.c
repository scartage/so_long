/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:18:43 by scartage          #+#    #+#             */
/*   Updated: 2022/11/11 22:51:53 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <string.h>

void	cant_take_collectibles(t_vars *vars, int aux)
{
	if (aux == 1)
		mlx_string_put(vars->mlx, vars->win_ptr, vars->px + 5, \
			vars->py + 10, 0x0000FF00, "take first all the collectibles");
	else if (aux == 2)
		mlx_string_put(vars->mlx, vars->win_ptr, vars->px + 5, \
			vars->py + 10, 0x0000FF00, "take first all the collectibles");
	else if (aux == 3)
		mlx_string_put(vars->mlx, vars->win_ptr, vars->px + 5, \
			vars->py + 10, 0x0000FF00, "take first all the collectibles");
	else if (aux == 4)
		mlx_string_put(vars->mlx, vars->win_ptr, vars->px + 5, \
			vars->py + 10, 0x0000FF00, "take first all the collectibles");
}

int	check_collectionable(t_vars *vars)
{
	if (vars->map[vars->px - 1][vars->py] == 'E' && vars->col != 0)
	{
		cant_take_collectibles(vars, 1);
		return (-1);
	}
	else if (vars->map[vars->px + 1][vars->py] == 'E' && vars->col != 0)
	{
		cant_take_collectibles(vars, 2);
		return (-1);
	}
	else if (vars->map[vars->px][vars->py - 1] == 'E' && vars->col != 0)
	{
		cant_take_collectibles(vars, 3);
		return (-1);
	}
	else if (vars->map[vars->px][vars->py + 1] == 'E' && vars->col != 0)
	{
		cant_take_collectibles(vars, 4);
		return (-1);
	}
	return (0);
}

int	playing_renders(t_vars *vars)
{
	char	*str;

	str = ft_strjoin(" Movements: ", ft_itoa(vars->counter));
	vars->frames++;
	if (vars->frames == 80)
		vars->frames = 0;
	print_game_map(vars);
	if (check_collectionable(vars) == -1)
		return (1);
	if (check_if_finished(vars) == 1)
		return (1);
	mlx_string_put(vars->mlx, vars->win_ptr, (vars->width * 50) \
		- 200, 10, 0x0000FF00, str);
	return (0);
}

/*To do: mejorar los mensaje que aparecen en la ventana del juego,
 * tienen que ir acorde con las dimensiones de la pantalla.*/
int	main(int ac, char **av)
{
	t_vars	vars;

	vars.col = 0;
	vars.alive = 1;
	vars.frames = 0;
	if (ac != 2)
		ft_perror("Error: ./so_long map.ber\n");
	ft_check_ext_file(av[1]);
	vars.map = read_file(av[1]);
	vars.map_copy = read_file(av[1]);
	if (ft_check_map(&vars) == 0)
		ft_printf("el mapa pasa los parametros\n");
	vars.mlx = mlx_init();
	reading_imgs(&vars);
	vars.win_ptr = mlx_new_window(vars.mlx, vars.width * SIZE, \
		vars.height * SIZE, "don't panic, it's just so_long_BONUS");
	vars.counter = 0;
	mlx_hook(vars.win_ptr, 2, 0, player_movs, &vars);
	mlx_hook(vars.win_ptr, 17, 0, free_memory, &vars);
	mlx_loop_hook(vars.mlx, playing_renders, &vars);
	mlx_loop(vars.mlx);
	free_memory(&vars);
	return (0);
}
