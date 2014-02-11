/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:43:51 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/22 18:43:51 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 && s2 && c && n)
	{
		while (i < n)
		{
			*((char *) s1 + i) = *((char *) s2 + i);
			if (*((char *) s2 + i) == (char) c)
			{
				return ((char *) s1 + i + 1);
			}
			i++;
		}
	}
	return (NULL);
}
