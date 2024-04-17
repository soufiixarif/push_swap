/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:04:26 by sarif             #+#    #+#             */
/*   Updated: 2024/04/17 16:49:05 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_it_top(t_stack **a, int min)
{
	if ((*a)->idx == min)
		return (1);
	else
		return (0);
}

void	make_it_top(t_stack **a, t_stack **b, int pos, int min)
{
	t_stack	*ptr;

	ptr = *a;
	while (ptr)
	{
		if (ptr->position == pos)
		{
			if (pos <= stacklen(*a) / 2)
				while (!check_if_it_top(a, min))
					ra(a);
			else
			{
				while (!check_if_it_top(a, min))
					rra(a);
			}
			pb(a, b);
			return ;
		}
		ptr = ptr->next;
	}
}


int	max(t_stack **a)
{
	int		max;
	t_stack	*ptr;

	ptr = *a;
	max = ptr->idx;
	while (ptr)
	{
		if (max < ptr->idx)
			max = ptr->idx;
		ptr = ptr->next;
	}
	return (max);
}

int	min(t_stack *a)
{
	int	min;

	min = a->idx;
	while (a)
	{
		if (min > a->idx)
			min = a->idx;
		a = a->next;
	}
	return (min);
}
