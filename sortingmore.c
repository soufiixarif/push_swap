/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingmore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:04:44 by sarif             #+#    #+#             */
/*   Updated: 2024/04/21 06:56:26 by sarif            ###   ########.fr       */
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

// void	makeorder(t_stack **a, t_stack **b)
// {
// 	t_stack	*ptr;
// 	int		smax;

// 	ptr = *b;
// 	smax = max(a);
// 	while (ptr)
// 	{
// 		if (ptr->idx == (*a)->idx - 1)
// 		{
// 			pa(a, b);
// 			// orderopti(a,b);
// 			while (buttom_is_available(a))
// 				rra(a, 1);
// 		}
// 		else if (max_in_buttom(a, smax) || lastidx(*a) < ptr->idx)
// 		{
// 			pa(a, b);
// 			ra(a, 1);
// 		}
// 		else
// 			make_correct_top(a, b);
// 		set_position(*b);
// 		ptr = *b;
// 	}
// }
void	makeorder2(t_stack **a, t_stack **b)
{
	int amax;

	amax = max(a);
	while (*b)
	{
		if ((*a)->idx -1 == (*b)->idx)
			pa(a, b);
		else if ((*a)->idx -1 == lastidx(*b))
			(rrb(b, 1), pa(a, b));
		else if (lastidx(*a) == amax)
			(pa(a, b) , ra(a, 1));
		else if (lastidx(*a) < (*b)->idx)
			(pa(a, b), ra(a, 1));
		else if (lastidx(*a) < lastidx(*b))
			(rrb(b, 1), pa(a,b), ra(a, 1));
		else if (lastidx(*a) == (*a)->idx - 1)
			rra(a, 1);
		else if(close_to_top(b,(*a)->idx - 1))
			rb(b, 1);
		else
			rrb(b, 1);
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
		if (ptr->idx == (*a)->idx - 1)
		{
			if (ptr->position <= stacklen(*b) / 2)
				rb(b, 1);
			else
				rrb(b, 1);
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

// void orderopti(t_stack **a, t_stack **b)
// {
// 	t_stack *ptr;

// 	ptr = *b;
// 	while (ptr)
// 	{
// 		while (buttom_is_available(a) && ptr->idx)
// 	}
// }
