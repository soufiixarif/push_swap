/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:04:26 by sarif             #+#    #+#             */
/*   Updated: 2024/04/13 21:01:28 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_it_top(t_stack *a, int min)
{
	if (a->n == min)
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
			{
				while (!check_if_it_top(*a, min))
					ra(a);
			}
			else
				while (!check_if_it_top(*a, min))
					rra(a);
			pb(a, b);
		}
		ptr = ptr->next;
	}
}

int	max(t_stack *a)
{
	int	max;

	max = a->n;
	while (a)
	{
		if (max < a->n)
			max = a->n;
		a = a->next;
	}
	return (max);
}

int	min(t_stack *a)
{
	int	min;

	min = a->n;
	while (a)
	{
		if (min > a->n)
			min = a->n;
		a = a->next;
	}
	return (min);
}
