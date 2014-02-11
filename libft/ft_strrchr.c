/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:44:04 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/09 15:33:16 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c2;

	i = ft_strlen((char *)s) + 1;
	c2 = (char) c;
	while (i > 0 && s[i] != c2)
		i--;
	if (s[i] == c2)
		return ((char *)&s[i]);
	return (NULL);
}
