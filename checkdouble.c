/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkdouble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 07:29:55 by sarif             #+#    #+#             */
/*   Updated: 2024/04/09 07:39:49 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkdouble(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->n == tmp->n)
			{
				printf("Error double value found\n");
				// s_free(&a);
				exit(EXIT_FAILURE);
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
}
