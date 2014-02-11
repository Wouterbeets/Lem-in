/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:44:00 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/22 18:44:00 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		strlen;
	char	*tmp;

	strlen = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	tmp = (char *)malloc(sizeof(*tmp) * (strlen));
	i = 0;
	if (tmp)
	{
		while (*s1)
			tmp[i++] = *s1++;
		while (*s2)
			tmp[i++] = *s2++;
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
