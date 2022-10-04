/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:09:14 by scartage          #+#    #+#             */
/*   Updated: 2022/07/08 18:54:38 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*comparas que dos strings sean exactamente iguales
 * si son iguales esta funcion retorna un 1*/

int	ft_strequal(char *s1, char *s2)
{
	if (s1 && s2)
		if (ft_strcmp(s1, s2) == 0)
			return (1);
	return (0);
}
