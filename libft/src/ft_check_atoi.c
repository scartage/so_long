/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:17:05 by scartage          #+#    #+#             */
/*   Updated: 2022/09/27 20:06:33 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <limits.h>

int	ft_check_atoi(char *str)
{
	long	i;
	int		sig;
	long	aux;

	i = 0;
	aux = 0;
	sig = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		aux = (aux * 10) + (str[i] - 48);
		i++;
	}
	aux = aux * sig;
	if (aux < INT_MIN || aux > INT_MAX)
		return (1);
	return (0);
}
