/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:37:04 by sarif             #+#    #+#             */
/*   Updated: 2024/04/23 10:01:55 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int checker)
{
	t_stack	*ptr;

	if (!a || !*a || !(*a)->next)
		return ;
	ptr = *a;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *a;
	(*a)->prev = ptr;
	*a = (*a)->next;
	(*a)->prev = NULL;
	ptr->next->next = NULL;
	if (checker == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int checker)
{
	t_stack	*ptr;

	if (!b || !*b || !(*b)->next)
		return ;
	ptr = *b;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *b;
	(*b)->prev = ptr;
	*b = (*b)->next;
	(*b)->prev = NULL;
	ptr->next->next = NULL;
	if (checker == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void	rra(t_stack **a, int checker)
{
	t_stack	*ptr;

	if (!a || !*a || !(*a)->next)
		return ;
	ptr = *a;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *a;
	(*a)->prev = ptr;
	(*a) = (*a)->prev;
	ptr->prev->next = NULL;
	(*a)->prev = NULL;
	if (checker == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int checker)
{
	t_stack	*ptr;

	if (!b || !*b || !(*b)->next)
		return ;
	ptr = *b;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *b;
	(*b)->prev = ptr;
	(*b) = (*b)->prev;
	ptr->prev->next = NULL;
	(*b)->prev = NULL;
	if (checker == 1)
		write(1, "rrb\n", 4);
}
