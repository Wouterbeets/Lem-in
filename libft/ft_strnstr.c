/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:44:03 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/22 18:44:03 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;

	if (ft_strlen((char *)s2) == 0)
		return ((char *)s1);
	if (ft_strlen((char *)s2) > (int)n)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && n > 0)
	{
		while ((s1[i] == s2[j]) && (s2[j]))
		{
			i++;
			j++;
		}
		if (ft_strlen((char *)s2) == j)
			return ((char *)(s1 + i - j));
		else
			i = i - j + 1;
		j = 0;
		n--;
	}
	return (NULL);
}
