/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 04:15:33 by sarif             #+#    #+#             */
/*   Updated: 2024/04/27 04:16:37 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	exitprogramme(t_stack **a, t_stack **b, char *action)
{
	s_free(a);
	s_free(b);
	free(action);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	executeaction(char *action, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(action, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(action, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(action, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(action, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(action, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(action, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(action, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(action, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(action, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(action, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(action, "rrr\n"))
		rrr(a, b, 0);
	else
		exitprogramme(a, b, action);
}
