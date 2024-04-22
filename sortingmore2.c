/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingmore2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:54:11 by sarif             #+#    #+#             */
/*   Updated: 2024/04/21 19:54:49 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	close_to_top(t_stack **b, int index)
{
	t_stack	*ptr;
	int		size;
	int		i;

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
	t_stack	*ptr;

	ptr = *a;
	while (ptr && ptr->next)
	{
		if (ptr->idx > ptr->next->idx)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
