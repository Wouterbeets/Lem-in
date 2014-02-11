/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:44:05 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/22 18:44:06 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (s && start && len)
	{
		i = 0;
		str = (char *)malloc(sizeof(s));
		while (len > 0)
		{
			str[i] = s[start];
			i++;
			start++;
			len--;
		}
		return (str);
	}
	return (NULL);
}
