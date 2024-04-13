/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targetfinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:43:21 by sarif             #+#    #+#             */
/*   Updated: 2024/04/12 16:04:09 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *targerfinder(t_stack *a, t_stack *b)
{
    t_stack *target;
    t_stack *tmp;
    long    index;

    while(b)
    {
        index = __LONG_MAX__;
        tmp = a;
        while(tmp)
        {
            if(tmp->n > b->n && tmp->n < index)
            {
                
            }
        }
                
    }
}