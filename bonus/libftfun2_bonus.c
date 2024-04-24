/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfun2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:55:34 by sarif             #+#    #+#             */
/*   Updated: 2024/04/24 20:24:08 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	long	tmp;

	i = 0;
	s = 1;
	r = 0;
	while (((str[i] >= 9 && str[i] <= 13) || (str[i] == 32)) && str[i])
		i++;
	s = ft_check_sign(str, &i);
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		tmp = r;
		r = (r * 10) + (str[i] - '0');
		i++;
	}
	return ((r * s));
}

int	is_sorted(t_stack *a)
{
	t_stack	*ptr;

	ptr = a;
	while (ptr && ptr->next)
	{
		if (ptr->n > ptr->next->n)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
