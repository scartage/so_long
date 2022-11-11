/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scartage <scartage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 17:37:27 by scartage          #+#    #+#             */
/*   Updated: 2022/11/11 20:49:04 by scartage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 * Si hay algun fallo hay que agrandar el buffer_size
 * o comprobar que lo que leyo el read sea menor al buffer,
 * para saber si leyo bien o si faltan datos.
 * El buffer size actual es de 5000
 */

char	*get_line(int fd)
{
	char	*aux;
	int		checker;

	checker = 0;
	aux = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (aux == NULL)
		return (NULL);
	checker = read(fd, aux, BUFFER_SIZE);
	if (checker == -1)
	{
		free(aux);
		return (NULL);
	}
	aux[checker] = '\0';
	return (aux);
}
