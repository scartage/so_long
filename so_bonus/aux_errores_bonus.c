/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_errores_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:19:24 by scartage          #+#    #+#             */
/*   Updated: 2022/11/11 21:10:50 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_perror_map(void)
{
	char	*msm;

	msm = "Error: Mapa incorrecto.\nRecuerde que los unicos caracteres validos son \
	{0, 1, C, E, P, X}.\nAdemas, solo puede haber 1 salida, 1 posicion incial y al menos \
	un colecionable.\nTambien puede revisar que el mapa no tenga saltos de linea incorrectos \
	o el que el mapa este vacio\n";
	ft_perror(msm);
}
