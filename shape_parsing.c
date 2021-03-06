/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 09:48:41 by mlu               #+#    #+#             */
/*   Updated: 2017/07/03 17:43:32 by jkrause          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utility.h"

void	write_shape(t_shape **ptr, char *s, int gsize)
{
	t_shape *shape;

	if (*ptr != 0)
	{
		shape = parse_shape(s, (*(ptr))->letter + 1, gsize);
		(*(ptr))->next = shape;
		*ptr = (*(ptr))->next;
	}
	else
	{
		shape = parse_shape(s, 'A', gsize);
		*ptr = shape;
	}
}

void	ft_parseshapes(char *str, int gridsize, t_shape **last_shape)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write_shape(last_shape, str + i, gridsize);
		i += 21;
	}
}
