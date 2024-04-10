/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:23:52 by sarif             #+#    #+#             */
/*   Updated: 2024/04/09 01:13:54 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*top1;
	t_stack	*top2;
	int		temp;

	if (*a == NULL || !(*a)->next)
		exit(EXIT_FAILURE);
	top1 = *a;
	top2 = top1->next;
	temp = top1->n;
	top1->n = top2->n;
	top2->n = temp;
	printf("sa\n");
}

void	sb(t_stack **b)
{
	t_stack	*top1;
	t_stack	*top2;
	int		temp;

	if (*b == NULL || !(*b)->next)
		exit(EXIT_FAILURE);
	top1 = *b;
	top2 = top1->next;
	temp = top1->n;
	top1->n = top2->n;
	top2->n = temp;
	printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	t_stack	*current;

	if (!b || !*b)
	{
		printf("stack b is empty\n");
		return ;
	}
	ptr = *b;
	pushtostack(a, ptr->n);
	current = (*b)->next;
	free(*b);
	*b = current;
	printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*ptr;
	t_stack	*current;

	if (!a || !*a)
		return ;
	ptr = *a;
	pushtostack(b, ptr->n);
	current = (*a)->next;
	free(*a);
	*a = current;
	printf("pb\n");
}

void	ra(t_stack **a)
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
	printf("ra\n");
}

void	rb(t_stack **b)
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
	printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	printf("rr\n");
}

void	rra(t_stack **a)
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
	printf("rra\n");
}

void	rrb(t_stack **b)
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
	printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	printf("rrr\n");
}
