/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingmore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:04:44 by sarif             #+#    #+#             */
/*   Updated: 2024/04/16 03:32:00 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunkpush(t_stack **a, t_stack **b, int min, int max)
{
	t_stack	*ptr;

	ptr = *a;
	while (ptr)
	{
		if (ptr->idx < (max + min) / 2)
			make_it_top(a, b, ptr->position, ptr->idx);
		else if (ptr->idx < max && ptr->idx >= (max + min) / 2)
		{
			make_it_top(a, b, ptr->position, ptr->idx);
			rb(b);
		}
		ptr = ptr->next;
	}
}

void	lastchunkpush(t_stack **a, t_stack **b, int min, int max)
{
	t_stack	*ptr;

	ptr = *a;
	while (ptr)
	{
		if (ptr->idx < (max + min) / 2 && ptr->idx < max - 3)
			make_it_top(a, b, ptr->position, ptr->n);
		else if (ptr->idx < max - 3 && ptr->idx >= (max + min) / 2)
		{
			make_it_top(a, b, ptr->position, ptr->n);
			rb(b);
		}
		ptr = ptr->next;
	}
}

void	makeorder(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	int		smax;

	ptr = *b;
	smax = max(*a);
	while (ptr)
	{
		if (ptr->n == (*a)->n - 1)
		{
			pa(a, b);
			while (buttom_is_available(a))
				rra(a);
		}
		else if (max_in_buttom(a, smax))
		{
			pa(a, b);
			ra(a);
		}
		else
			rb(b);
		// printf("value of head %d\n",ptr->idx);
		ptr = *b;
	}
}

int	max_in_buttom(t_stack **a, int max)
{
	t_stack	*ptr;

	ptr = *a;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	if (ptr->n == max)
		return (1);
	else
		return (0);
}

int	buttom_is_available(t_stack **a)
{
	t_stack	*ptr;
	int		value;

	ptr = *a;
	value = (*a)->n - 1;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	if (ptr->n == value)
		return (1);
	else
		return (0);
}
