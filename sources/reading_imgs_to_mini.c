/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_imgs_to_mini.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 20:02:09 by scartage          #+#    #+#             */
/*   Updated: 2022/10/18 20:07:52 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keep_reading_imgs(t_vars *vars, int height, int width)
{
	vars->imgs[3].img_ptr = mlx_xpm_file_to_image(vars->mlx, "imagenes/heroe_w.xpm", &width, &height);
	vars->imgs[3].data = mlx_get_data_addr(vars->imgs[3].img_ptr, &vars->imgs[3].bpp, &vars->imgs[3].size, &vars->imgs[3].endian);

	vars->imgs[5].img_ptr = mlx_xpm_file_to_image(vars->mlx, "imagenes/heroe_s.xpm", &width, &height);
	vars->imgs[5].data = mlx_get_data_addr(vars->imgs[5].img_ptr, &vars->imgs[5].bpp, &vars->imgs[5].size, &vars->imgs[5].endian);
	
	vars->imgs[6].img_ptr = mlx_xpm_file_to_image(vars->mlx, "imagenes/heroe_a.xpm", &width, &height);
	vars->imgs[6].data = mlx_get_data_addr(vars->imgs[6].img_ptr, &vars->imgs[6].bpp, &vars->imgs[6].size, &vars->imgs[6].endian);
	
	vars->imgs[7].img_ptr = mlx_xpm_file_to_image(vars->mlx, "imagenes/heroe_d.xpm", &width, &height);
	vars->imgs[7].data = mlx_get_data_addr(vars->imgs[7].img_ptr, &vars->imgs[7].bpp, &vars->imgs[7].size, &vars->imgs[7].endian);
}

void	reading_imgs(t_vars *vars)
{
	int	height;		//alto_img
	int width;		//ancho_img

	vars->imgs = malloc(sizeof(t_img) * (8));
	
	vars->imgs[0].img_ptr = mlx_xpm_file_to_image(vars->mlx, "imagenes/pared.xpm", &width, &height);
	vars->imgs[0].data = mlx_get_data_addr(vars->imgs[0].img_ptr, &vars->imgs[0].bpp, &vars->imgs[0].size, &vars->imgs[0].endian);

	vars->imgs[1].img_ptr = mlx_xpm_file_to_image(vars->mlx, "imagenes/espacio.xpm", &width, &height);
	vars->imgs[1].data = mlx_get_data_addr(vars->imgs[1].img_ptr, &vars->imgs[1].bpp, &vars->imgs[1].size, &vars->imgs[1].endian);
	
	vars->imgs[2].img_ptr = mlx_xpm_file_to_image(vars->mlx, "imagenes/coleccionable.xpm", &width, &height);
	vars->imgs[2].data = mlx_get_data_addr(vars->imgs[2].img_ptr, &vars->imgs[2].bpp, &vars->imgs[2].size, &vars->imgs[2].endian);

	vars->imgs[4].img_ptr = mlx_xpm_file_to_image(vars->mlx, "imagenes/exit.xpm", &width, &height);
	vars->imgs[4].data = mlx_get_data_addr(vars->imgs[4].img_ptr, &vars->imgs[4].bpp, &vars->imgs[4].size, &vars->imgs[4].endian);

	keep_reading_imgs(vars, height, width);
}
