/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:19:43 by sarif             #+#    #+#             */
/*   Updated: 2024/04/16 03:24:50 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_min(t_stack *a)
{
	long	min;
	t_stack *ptr;

	min = 2147483648;
	ptr = a;
	while (ptr)
	{
		if (min > ptr->n && ptr->check == 0)
			min = ptr->n;
		ptr = ptr->next;
	}
	return (min);
}

void	indexing(t_stack *a)
{
	long	min;
	int		index;
	t_stack	*tmp;

	tmp = a;
	index = 0;
	min = get_min(a);
	while (min != 2147483648)
	{
		while (a)
		{
			if (min == a->n)
			{
				a->idx = index;
				index++;
				a->check = 1;
				break ;
			}
			a = a->next;
		}
		a = tmp;
		min = get_min(a);
	}
}

void	set_position(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a->position = i++;
		a = a->next;
	}
}
