/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_errores.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:18:28 by scartage          #+#    #+#             */
/*   Updated: 2022/10/11 20:00:31 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_cherror(char c)
{
	write(2, &c, 1);
}

static void	ft_put_error(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_put_cherror(str[i]);
		i++;
	}
}

int	ft_perror(char *str)
{
	ft_put_error(str);
	exit(-1);
}

void ft_perror_map()
{
	char *msm = "Error: Mapa incorrecto.\nRecuerde que los unicos caracteres valido son {0, 1, C, E, P}.\nAdemas, solo puede haber 1 salida, 1 coleccionable y 1 posicion incial.\nTambien puede revisar que el mapa no tenga saltos de linea incorrectos o el que el mapa este vacio\n";

	ft_perror(msm);
}
