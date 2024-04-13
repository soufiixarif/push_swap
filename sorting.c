/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:13:17 by sarif             #+#    #+#             */
/*   Updated: 2024/04/13 00:58:08 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_if_it_top(t_stack *a, int min)
{
    if (a->n == min)
        return (1);
    else
        return (0);
}
void make_it_top(t_stack **a, t_stack **b, int pos, int min)
{
    t_stack *ptr;
    (void)b;

    ptr = *a;
    while (ptr)
    {
        if (ptr->position == pos)
        {
            if (pos <= stacklen(*a) / 2)
            {
                while (!check_if_it_top(*a,min))
                    ra(a);
            }
            else
                while (!check_if_it_top(*a,min))
                    rra(a);
            pb(a,b);
        }
        ptr = ptr->next;
    }
}

int	max(t_stack *a)
{
	int	max;

	max = a->n;
	while (a)
	{
		if (max < a->n)
			max = a->n;
		a = a->next;
	}
	return (max);
}

int	min(t_stack *a)
{
	int	min;

	min = a->n;
	while (a)
	{
		if (min > a->n)
			min = a->n;
		a = a->next;
	}
	return (min);
}

void	sortingfive(t_stack **a, t_stack **b)
{
	long     minimum;
    t_stack *ptr;
    int     push;

    push = 0;
    while (push != 2)
    {
        minimum = min(*a);
        ptr = *a;
        while (ptr)
        {
            if (ptr->n == minimum)
                make_it_top(a,b,ptr->position,minimum);
            ptr = ptr->next;
        }
        set_position(*a);
        push++;
    }
    sortingthree(a);
    if ((*b)->n < (*b)->next->n)
        sa(a);
    pa(a,b);
    pa(a,b);
}

void	sortingthree(t_stack **a)
{
	if ((*a)->n == max(*a))
		ra(a);
	else if ((*a)->next->n == max(*a))
		rra(a);
	if ((*a)->n > (*a)->next->n)
		sa(a);
}

void	sorting(t_stack **a, t_stack **b)
{
	int	len = stacklen(*a);
    (void)b;

	indexing(*a);
	if (len == 3)
		sortingthree(a);
	else if (len <= 5)
		sortingfive(a, b);
	// else

}
