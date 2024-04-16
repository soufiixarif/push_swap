/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:04:26 by sarif             #+#    #+#             */
/*   Updated: 2024/04/16 03:30:06 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_it_top(t_stack *a, int min)
{
	if (a->idx == min)
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
				while (!check_if_it_top(*a, min))
				{
					printf("");
					ra(a);
				}
			else
				while (!check_if_it_top(*a, min))
					rra(a);
			pb(a, b);
		}
		ptr = ptr->next;
	}
	set_position(*a);
}


int	max(t_stack *a)
{
	int	max;

	max = a->idx;
	while (a)
	{
		if (max < a->idx)
			max = a->idx;
		a = a->next;
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
