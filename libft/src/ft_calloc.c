/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 19:10:53 by scartage          #+#    #+#             */
/*   Updated: 2022/04/19 20:06:39 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*g;

	g = malloc(count * size);
	if (g == NULL)
		return (NULL);
	ft_bzero(g, (count * size));
	return (g);
}
