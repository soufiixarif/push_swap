/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:23:52 by sarif             #+#    #+#             */
/*   Updated: 2024/04/23 10:01:18 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int checker)
{
	t_stack	*top1;
	t_stack	*top2;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	top1 = *a;
	top2 = top1->next;
	top1->prev = top2;
	top2->prev = NULL;
	top1->next = top2->next;
	if (top2->next != NULL)
		top2->next->prev = top1;
	top2->next = top1;
	*a = top2;
	if (checker == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int checker)
{
	t_stack	*top1;
	t_stack	*top2;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	top1 = *b;
	top2 = top1->next;
	top1->prev = top2;
	top2->prev = NULL;
	top1->next = top2->next;
	if (top2->next != NULL)
		top2->next->prev = top1;
	top2->next = top1;
	*b = top2;
	if (checker == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	ptr = *b;
	if (*b == NULL)
		return ;
	*b = (*b)->next;
	if (*a != NULL)
		(*a)->prev = ptr;
	ptr->next = *a;
	ptr->prev = NULL;
	*a = ptr;
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	ptr = *a;
	if (*a == NULL)
		return ;
	*a = (*a)->next;
	if (*b != NULL)
		(*b)->prev = ptr;
	ptr->next = *b;
	ptr->prev = NULL;
	*b = ptr;
	write(1, "pb\n", 3);
}
