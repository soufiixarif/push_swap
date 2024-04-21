/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:13:17 by sarif             #+#    #+#             */
/*   Updated: 2024/04/21 18:13:15 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortingmore(t_stack **a, t_stack **b)
{
	int		len;

	len = stacklen(*a);
	chunkpush(a, b, 0, (len / 4));
	chunkpush(a, b, len / 4, len / 2);
	chunkpush(a, b, len / 2, len * 3/ 4);
	lastchunkpush(a, b, len * 3 / 4, len);
	sortingthree(a);
	makeorder(a, b);
	while(is_sorted(a))
	{
		rra(a,1);
	}

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
			if (ptr->idx == minimum)
				make_it_top(a, b, ptr->position, minimum);
			ptr = ptr->next;
		}
		set_position(*a);
		push++;
	}
	sortingthree(a);
	if ((*b)->n < (*b)->next->n)
		sa(a, 1);
	pa(a, b);
	pa(a, b);
}

void	sortingthree(t_stack **a)
{
	if ((*a)->idx == max(a))
		ra(a, 1);
	else if ((*a)->next->idx == max(a))
		rra(a, 1);
	if ((*a)->idx > (*a)->next->idx)
		sa(a, 1);
}

void	sorting(t_stack **a, t_stack **b)
{
	int	len;

	len = stacklen(*a);
	// indexing(*a);
	if (len == 3)
		sortingthree(a);
	else if (len <= 5)
		sortingfive(a, b);
	else
		sortingmore(a, b);
}
