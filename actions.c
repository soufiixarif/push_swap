/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:23:52 by sarif             #+#    #+#             */
/*   Updated: 2024/04/21 18:09:51 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int checker)
{
    t_stack *top1;
    t_stack *top2;

	if (*a == NULL || (*a)->next == NULL)
        return;
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
    	printf("sa\n");
}

void	sb(t_stack **b, int checker)
{
    t_stack *top1;
    t_stack *top2;

	if (*b == NULL || (*b)->next == NULL)
        return;
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
		printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
    t_stack *ptr;
	
	ptr = *b;
	if (*b == NULL)
        return;
    *b = (*b)->next;
    if (*a != NULL)
        (*a)->prev = ptr;
    ptr->next = *a;
    ptr->prev = NULL;
    *a = ptr;
    printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
    t_stack *ptr;
	
	ptr = *a;
	if (*a == NULL)
        return;
    *a = (*a)->next;
    if (*b != NULL)
        (*b)->prev = ptr;
    ptr->next = *b;
    ptr->prev = NULL;
    *b = ptr;
    printf("pb\n");
}

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
		printf("ra\n");
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
		printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	printf("rr\n");
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
		printf("rra\n");
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
		printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	printf("rrr\n");
}