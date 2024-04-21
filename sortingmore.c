/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingmore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:04:44 by sarif             #+#    #+#             */
/*   Updated: 2024/04/21 18:13:27 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunkpush(t_stack **a, t_stack **b, int min, int max)
{
	t_stack	*ptr;
	int		len;
	int		i;

	ptr = *a;
	len = max - min;
	i = 0;
	while (i < len)
	{
		if (ptr->idx < (max + min) / 2)
		{
			make_it_top(a, b, ptr->position, ptr->idx);
			if (optimisation(a, max))
				rr(a,b);
			else
				rb(b, 1);
		}
		else if (ptr->idx < max && ptr->idx >= (max + min) / 2)
			make_it_top(a, b, ptr->position, ptr->idx);
		else
		{
			ptr = ptr->next;
			continue;
		}
		set_position(*a);
		ptr = *a;
		i++;
	}
}

void	lastchunkpush(t_stack **a, t_stack **b, int min, int max)
{
	t_stack	*ptr;
	int		i;
	int		len;

	ptr = *a;
	len = max - min - 3;
	i = 0;
	while (i < len)
	{
		if (ptr->idx < (max + min) / 2 && ptr->idx < max - 3)
		{	
			make_it_top(a, b, ptr->position, ptr->idx);
			if (optimisation(a,max - 3))
				rr(a,b);
			else
				rb(b, 1);
		}
		else if (ptr->idx < max - 3 && ptr->idx >= (max + min) / 2)
			make_it_top(a, b, ptr->position, ptr->idx);
		else
		{
			ptr = ptr->next;
			continue ;
		}
		set_position(*a);
		ptr = *a;
		i++;
	}
}

void	makeorder(t_stack **a, t_stack **b)
{
	int amax;

	amax = max(a);
	while (stacklen(*b) > 0)
	{
		if ((*b) && (*a)->idx -1 == (*b)->idx)
			pa(a, b);
		else if ((*b) && (*a)->idx -1 == lastidx(*b))
			(rrb(b, 1), pa(a, b));
		else if (lastidx(*a) == amax)
			(pa(a, b) , ra(a, 1));
		else if ((*b) && lastidx(*a) < (*b)->idx)
			(pa(a, b), ra(a, 1));
		else if ((*b) && lastidx(*a) < lastidx(*b))
			(rrb(b, 1), pa(a,b), ra(a, 1));
		else if (lastidx(*a) == (*a)->idx - 1)
			rra(a, 1);
		else if((*b) && close_to_top(b,(*a)->idx - 1))
			rb(b, 1);
		else
			rrb(b, 1);
	}
}

int lastidx(t_stack *a)
{
	t_stack *ptr;

	ptr = a;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	return(ptr->idx);
}

int optimisation(t_stack **a, int max)
{
	t_stack *ptr;

	ptr = *a;
	if (ptr->idx >= max)
		return(1);
	else
		return (0);
}

int close_to_top(t_stack **b, int index)
{
	t_stack *ptr;
	int size;
	int i;

	i = 0;
	ptr = *b;
	size = stacklen(*b);
	while (ptr && i++ < (size / 2))
	{
		if (ptr->idx == index)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
 int	is_sorted(t_stack **a)
 {
	t_stack *ptr;

	ptr = *a;
	while(ptr && ptr->next)
	{
		if (ptr->idx > ptr->next->idx)
			return (1);
		ptr = ptr->next;
	}
	return (0);
 }
