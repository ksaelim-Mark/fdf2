/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaelim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:11:19 by ksaelim           #+#    #+#             */
/*   Updated: 2022/03/26 00:34:11 by ksaelim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dst;

	i = 0;
	while (s1[i] != '\0')
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	i = -1;
	while (s1[++i] != '\0')
	{
		dst[i] = s1[i];
	}
	dst[i] = '\0';
	return (dst);
}
