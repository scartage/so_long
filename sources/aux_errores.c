/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_errores.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:18:28 by scartage          #+#    #+#             */
/*   Updated: 2022/10/04 19:18:51 by scartage         ###   ########.fr       */
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
	while (str[i])
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
