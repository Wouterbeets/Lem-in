/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:44:00 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/22 18:44:00 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	re;

	re = 0;
	i = -1;
	while (src[++i])
			;
	re = i;
	i = -1;
	while (dst[++i] && i < size)
			;
	re += (i < size) ? i : size;
	if ((int)(size - ft_strlen(dst) - 1) > 0)
		ft_strncat(dst, src, size - ft_strlen(dst) - 1);
	return (re);
}
