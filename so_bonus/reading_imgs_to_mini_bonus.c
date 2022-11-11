/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_imgs_to_mini_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:21:27 by scartage          #+#    #+#             */
/*   Updated: 2022/11/11 22:20:58 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	reading_exit_imgs(t_vars *vars, int height, int width)
{
	vars->imgs[4].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/bonus/exit_big.xpm", &width, &height);
	vars->imgs[4].data = mlx_get_data_addr(vars->imgs[4].img_ptr, \
		&vars->imgs[4].bpp, &vars->imgs[4].size, &vars->imgs[4].endian);
	vars->imgs[9].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/bonus/exit_mid.xpm", &width, &height);
	vars->imgs[9].data = mlx_get_data_addr(vars->imgs[9].img_ptr, \
		&vars->imgs[9].bpp, &vars->imgs[9].size, &vars->imgs[9].endian);
	vars->imgs[10].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/bonus/exit_mid_mid.xpm", &width, &height);
	vars->imgs[10].data = mlx_get_data_addr(vars->imgs[10].img_ptr, \
		&vars->imgs[10].bpp, &vars->imgs[10].size, &vars->imgs[10].endian);
	vars->imgs[11].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/bonus/exit_mid_petit.xpm", &width, &height);
	vars->imgs[11].data = mlx_get_data_addr(vars->imgs[11].img_ptr, \
		&vars->imgs[11].bpp, &vars->imgs[11].size, &vars->imgs[11].endian);
	vars->imgs[12].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/bonus/no_exit_mid.xpm", &width, &height);
	vars->imgs[12].data = mlx_get_data_addr(vars->imgs[12].img_ptr, \
		&vars->imgs[12].bpp, &vars->imgs[12].size, &vars->imgs[12].endian);
}

void	reading_enemys_imgs(t_vars *vars, int height, int width)
{
	vars->imgs[13].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/bonus/no_black_hole.xpm", &width, &height);
	vars->imgs[13].data = mlx_get_data_addr(vars->imgs[13].img_ptr, \
		&vars->imgs[13].bpp, &vars->imgs[13].size, &vars->imgs[13].endian);
	vars->imgs[14].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/bonus/black_hole_petit.xpm", &width, &height);
	vars->imgs[14].data = mlx_get_data_addr(vars->imgs[14].img_ptr, \
		&vars->imgs[14].bpp, &vars->imgs[14].size, &vars->imgs[14].endian);
	vars->imgs[15].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/bonus/black_hole_midmid.xpm", &width, &height);
	vars->imgs[15].data = mlx_get_data_addr(vars->imgs[15].img_ptr, \
		&vars->imgs[15].bpp, &vars->imgs[15].size, &vars->imgs[15].endian);
	vars->imgs[16].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/bonus/black_hole_mid.xpm", &width, &height);
	vars->imgs[16].data = mlx_get_data_addr(vars->imgs[16].img_ptr, \
		&vars->imgs[16].bpp, &vars->imgs[16].size, &vars->imgs[16].endian);
	vars->imgs[17].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/bonus/black_hole_big.xpm", &width, &height);
	vars->imgs[17].data = mlx_get_data_addr(vars->imgs[17].img_ptr, \
		&vars->imgs[17].bpp, &vars->imgs[17].size, &vars->imgs[17].endian);
}

void	reading_mortys_faces(t_vars *vars, int height, int width)
{
	vars->imgs[3].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/morty_face_w.xpm", &width, &height);
	vars->imgs[3].data = mlx_get_data_addr(vars->imgs[3].img_ptr, \
		&vars->imgs[3].bpp, &vars->imgs[3].size, &vars->imgs[3].endian);
	vars->imgs[5].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/morty_face_s.xpm", &width, &height);
	vars->imgs[5].data = mlx_get_data_addr(vars->imgs[5].img_ptr, \
		&vars->imgs[5].bpp, &vars->imgs[5].size, &vars->imgs[5].endian);
	vars->imgs[6].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/morty_face_a.xpm", &width, &height);
	vars->imgs[6].data = mlx_get_data_addr(vars->imgs[6].img_ptr, \
		&vars->imgs[6].bpp, &vars->imgs[6].size, &vars->imgs[6].endian);
	vars->imgs[7].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/morty_face_d.xpm", &width, &height);
	vars->imgs[7].data = mlx_get_data_addr(vars->imgs[7].img_ptr, \
		&vars->imgs[7].bpp, &vars->imgs[7].size, &vars->imgs[7].endian);
}

void	reading_imgs(t_vars *vars)
{
	int	height;
	int	width;

	vars->imgs = malloc(sizeof(t_img) * (20));
	if (vars->imgs == NULL)
		ft_perror("Error: fallo de memoria en malloc de reading_imgs");
	vars->imgs[0].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/pared.xpm", &width, &height);
	vars->imgs[0].data = mlx_get_data_addr(vars->imgs[0].img_ptr, \
		&vars->imgs[0].bpp, &vars->imgs[0].size, &vars->imgs[0].endian);
	vars->imgs[1].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/espacio.xpm", &width, &height);
	vars->imgs[1].data = mlx_get_data_addr(vars->imgs[1].img_ptr, \
		&vars->imgs[1].bpp, &vars->imgs[1].size, &vars->imgs[1].endian);
	vars->imgs[2].img_ptr = mlx_xpm_file_to_image(vars->mlx, \
		"imagenes/img_for_final/mega_semilla.xpm", &width, &height);
	vars->imgs[2].data = mlx_get_data_addr(vars->imgs[2].img_ptr, \
		&vars->imgs[2].bpp, &vars->imgs[2].size, &vars->imgs[2].endian);
	reading_exit_imgs(vars, height, width);
	reading_mortys_faces(vars, height, width);
	reading_enemys_imgs(vars, height, width);
}
