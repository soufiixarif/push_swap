/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:13:17 by sarif             #+#    #+#             */
/*   Updated: 2024/04/16 03:32:36 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortingmore(t_stack **a, t_stack **b)
{
	int		len;

	len = stacklen(*a);
	chunkpush(a, b, 0, (len / 3));
	printf("======1=========\n");
	chunkpush(a, b, len / 3, len * 2 / 3);
	printf("======2=========\n");
	lastchunkpush(a, b, len * 2 / 3, len);
	printf("======3=========\n");
	sortingthree(a);
	printf("======4=========\n");
	// makeorder(a, b);
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
		sa(a);
	pa(a, b);
	pa(a, b);
}

void	sortingthree(t_stack **a)
{
	if ((*a)->idx == max(*a))
		ra(a);
	else if ((*a)->next->idx == max(*a))
		rra(a);
	if ((*a)->idx > (*a)->next->idx)
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
