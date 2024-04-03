/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:23:52 by sarif             #+#    #+#             */
/*   Updated: 2024/04/02 18:18:13 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(mystack **a)
{
    mystack *top1;
	mystack *top2;
	int temp;

	if (*a == NULL || !(*a)->next)
		exit(EXIT_FAILURE);
	top1 = *a;
	top2 = top1->next;
	temp = top1->n;
	top1->n = top2->n;
	top2->n = temp;
}

void sb(mystack **b)
{
    mystack *top1;
	mystack *top2;
	int temp;

	if (*b == NULL || !(*b)->next)
		exit(EXIT_FAILURE);
	top1 = *b;
	top2 = top1->next;
	temp = top1->n;
	top1->n = top2->n;
	top2->n = temp;
}

void ss(mystack **a, mystack **b)
{
    sa(a);
    sb(b);
}

void pa(mystack **a, mystack **b)
{
	mystack *ptr;
	mystack *current;

	if(!b || !*b)
	{
		printf("stack b is empty\n");
		return ;
	}
	ptr = *b;
	pushtostack(a,ptr->n);
	current = (*b)->next;
	free(*b);
	*b = current;
}

void pb(mystack **a, mystack **b)
{
	mystack *ptr;
	mystack *current;

	if(!a || !*a)
		return ;
	ptr = *a;
	pushtostack(b,ptr->n);
	current = (*a)->next;
	free(*a);
	*a = current;
}

void ra(mystack **a)
{
    mystack *ptr;
	
    if (!a || !*a || !(*a)->next)
        return;
	ptr = *a;
    while (ptr->next)
        ptr = ptr->next;

    ptr->next = *a;
    (*a)->prev = ptr;
    *a = (*a)->next;
    (*a)->prev = NULL;
    ptr->next->next = NULL;
}

void rb(mystack **b)
{
    mystack *ptr;
	
    if (!b || !*b || !(*b)->next)
        return;
	ptr = *b;
    while (ptr->next)
        ptr = ptr->next;

    ptr->next = *b;
    (*b)->prev = ptr;
    *b = (*b)->next;
    (*b)->prev = NULL;
    ptr->next->next = NULL;
}

void rr(mystack **a, mystack **b)
{
    ra(a);
    rb(b);
}

void rra(mystack **a)
{
	mystack *ptr;
	
    if (!a || !*a || !(*a)->next)
        return;
	ptr = *a;
    while (ptr->next)
        ptr = ptr->next;

    ptr->next = *a;
    (*a)->prev = ptr;
    (*a) = (*a)->prev;
    ptr->prev->next = NULL;
    (*a)->prev = NULL;
}

void rrb(mystack **b)
{
	mystack *ptr;
	
    if (!b || !*b || !(*b)->next)
        return;
	ptr = *b;
    while (ptr->next)
        ptr = ptr->next;

    ptr->next = *b;
    (*b)->prev = ptr;
    (*b) = (*b)->prev;
    ptr->prev->next = NULL;
    (*b)->prev = NULL;
}

void rrr(mystack **a, mystack **b)
{
    rra(a);
    rrb(b);
}