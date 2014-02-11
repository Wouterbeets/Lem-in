/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:43:57 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/22 18:43:57 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		ret;

	ret = 0;
	while (!(ret = *(unsigned char *) s1 - *(unsigned char *) s2) && *s2)
	{
		++s1;
		++s2;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1 ;
	return (ret);
}
