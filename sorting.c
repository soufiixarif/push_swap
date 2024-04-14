/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:13:17 by sarif             #+#    #+#             */
/*   Updated: 2024/04/14 23:15:12 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortingmore(t_stack **a, t_stack **b)
{
	int		len;

	len = stacklen(*a);
	chunkpush(a, b, 0, (len / 3));
	chunkpush(a, b, len / 3, len * 2 / 3);
	lastchunkpush(a, b, len * 2 / 3, len);
	sortingthree(a);
	makeorder(a, b);
}

void	sortingfive(t_stack **a, t_stack **b)
{
	long	minimum;
	t_stack	*ptr;
	int		push;

	push = 0;
	while (push != 2)
	{
		minimum = min(*a);
		ptr = *a;
		while (ptr)
		{
			if (ptr->n == minimum)
				make_it_top(a, b, ptr->position, minimum);
			ptr = ptr->next;
		}
		set_position(*a);
		push++;
	}
	sortingthree(a);
	if ((*b)->n < (*b)->next->n)
		sa(a);
	pa(a, b);
	pa(a, b);
}

void	sortingthree(t_stack **a)
{
	if ((*a)->n == max(*a))
		ra(a);
	else if ((*a)->next->n == max(*a))
		rra(a);
	if ((*a)->n > (*a)->next->n)
		sa(a);
}

void	sorting(t_stack **a, t_stack **b)
{
	int	len;

	len = stacklen(*a);
	indexing(*a);
	if (len == 3)
		sortingthree(a);
	else if (len <= 5)
		sortingfive(a, b);
	else
		sortingmore(a, b);
}
