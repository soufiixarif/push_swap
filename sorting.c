/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:13:17 by sarif             #+#    #+#             */
/*   Updated: 2024/04/07 16:39:05 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int max(mystack *a)
{
    int max = a->n;
    while(a)
    {
        if (max < a->n)
            max = a->n;
        a = a->next;
    }
    return(max);
}

void sortingfive(mystack **a, mystack **b)
{
    pb(a,b);
    pb(a,b);
    sortingthree(a);
    if((*b)->n > (*a)->n)
    {   
        pa(a,b);
        ra(a);
    }
    else
        pa(a,b);
    if((*b)->n > (*a)->n)
    {   
        pa(a,b);
        ra(a);
    }
    else
        pa(a,b);
}
void sortingthree(mystack **a)
{
    if((*a)->n == max(*a))
    {
        ra(a);
        if((*a)->n > (*a)->next->n)
            sa(a);
    }
    else if((*a)->next->n == max(*a))
    {
        rra(a);
        if((*a)->n > (*a)->next->n)
            sa(a);
    }
    else
        if((*a)->n > (*a)->next->n)
            sa(a);
}

void sorting(mystack **a, mystack **b)
{
    int len = stacklen(a);
    (void)b;

    if(len == 3)
        sortingthree(a);
    if (len == 5)
        sortingfive(a,b);
}