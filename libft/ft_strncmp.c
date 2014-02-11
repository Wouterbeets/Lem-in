/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:44:02 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/22 09:44:02 by wbeets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		re;

	re = 0;
	while (!(re = *(unsigned char *) s1 - *(unsigned char *) s2) && *s2 && n--)
	{
		++s1;
		++s2;
	}
	if (re < 0)
		re = -1;
	else if (re > 0)
		re = 1 ;
	return (re);
}
