/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingmore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 18:04:44 by sarif             #+#    #+#             */
/*   Updated: 2024/04/13 22:02:03 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chunkpush(t_stack **a, t_stack **b, int len)
{
	t_stack	*ptr;

	ptr = *a;
	while (ptr)
	{
		printf("number %d index %d len /2 %d\n",ptr->n, ptr->idx, len/2);	
		if (ptr->idx <= len / 2)
		{
			make_it_top(a, b, ptr->position, ptr->n);
			set_position(*a);
		}
		else if (ptr->idx < len && ptr->idx > len / 2)
		{
			make_it_top(a, b, ptr->position, ptr->n);
			rb(b);
			set_position(*a);
		}
		ptr = ptr->next;
	}
}

void	lastchunkpush(t_stack **a, t_stack **b, int len)
{
	t_stack	*ptr;
	int		slen;

	ptr = *a;
	slen = stacklen(*a);
	while (push < len - 3)
	{
		
	}
	
}
