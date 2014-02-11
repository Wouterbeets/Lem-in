/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/22 18:43:38 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/22 18:43:41 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		is_neg;
	int		val;

	is_neg = 0;
	val = 0;
	while ((*str == '\t') || (*str == '\v')
			|| (*str == '\n') || (*str == '\r')
			|| (*str == '\f') || (*str == ' '))
		str++;
	if (*str == '-')
	{
		is_neg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
			val = (val * 10) + (*str - 48) % 10;
			str++;
	}
	return (val = is_neg ? val * -1 : val);
}
