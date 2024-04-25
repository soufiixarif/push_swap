/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfun2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:34 by sarif             #+#    #+#             */
/*   Updated: 2024/04/24 20:30:51 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atoi(const char *str)
{
	int		i;
	long	r;
	long	s;

	i = 0;
	s = 1;
	r = 0;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)) && str[i])
		i++;
	s = ft_check_sign(str, &i);
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	return ((r * s));
}
