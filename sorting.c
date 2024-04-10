/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:13:17 by sarif             #+#    #+#             */
/*   Updated: 2024/04/09 17:21:05 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sortingfive(t_stack **a, t_stack **b)
{
	pb(a, b);
	pb(a, b);
	sortingthree(a);
	if ((*b)->n > (*a)->n)
	{
		pa(a, b);
		ra(a);
	}
	else
		pa(a, b);
	if ((*b)->n > (*a)->n)
	{
		pa(a, b);
		ra(a);
	}
	else
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
	int	len = stacklen(a);

	indexing(*a);
	if (len == 3)
		sortingthree(a);
	else if (len <= 5)
		sortingfive(a, b);
	// else

}
