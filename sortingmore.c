/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingmore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:04:44 by sarif             #+#    #+#             */
/*   Updated: 2024/04/17 02:38:53 by sarif            ###   ########.fr       */
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
			// rb(b);
			ptr = *a;
		}
		else if (ptr->idx < max && ptr->idx >= (max + min) / 2)
		{
			make_it_top(a, b, ptr->position, ptr->idx);
			ptr = *a;
		}
		else
		{
			ptr = ptr->next;
			continue;
		}
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
			// rb(b);
		}
		else if (ptr->idx < max - 3 && ptr->idx >= (max + min) / 2)
		{
			make_it_top(a, b, ptr->position, ptr->idx);
		}
		else
		{
			ptr = ptr->next;
			continue ;
		}
		ptr = *a;
		i++;
	}
}

void	makeorder(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	int		smax;

	ptr = *b;
	smax = max(a);
	while (ptr)
	{
		if (ptr->idx == (*a)->idx - 1)
		{
			pa(a, b);
			while (buttom_is_available(a))
				rra(a);
		}
		else if (max_in_buttom(a, smax) || lastidx(*a) < ptr->idx)
		{
			pa(a, b);
			ra(a);
		}
		else
			make_correct_top(a, b);
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
	if (ptr->idx == max)
		return (1);
	else
		return (0);
}

int	buttom_is_available(t_stack **a)
{
	t_stack	*ptr;
	int		value;

	ptr = *a;
	value = (*a)->idx - 1;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	if (ptr->idx == value)
		return (1);
	else
		return (0);
}

void	make_correct_top(t_stack **a, t_stack **b)
{
	t_stack *ptr;

	ptr = *b;
	while (ptr)
	{
		if (ptr->idx == (*a)->idx  -1)
		{
			if (ptr->position <= stacklen(*b) / 2)
				rb(b);
			else
				rrb(b);
			break;
		}
		ptr = ptr->next;
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