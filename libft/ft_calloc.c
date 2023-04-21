/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 23:24:44 by ksaelim           #+#    #+#             */
/*   Updated: 2022/04/19 21:55:56 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	i;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	i = count * size;
	s = malloc(i);
	if (!s)
		return (NULL);
	ft_bzero(s, i);
	return (s);
}	
