/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingmore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:04:44 by sarif             #+#    #+#             */
/*   Updated: 2024/04/14 05:39:29 by sarif            ###   ########.fr       */
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
			make_it_top(a, b, ptr->position, ptr->n);
		else if (ptr->idx < max && ptr->idx >= (max + min) / 2)
		{
			make_it_top(a, b, ptr->position, ptr->n);
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
