/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:09:58 by sarif             #+#    #+#             */
/*   Updated: 2024/04/24 20:17:10 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	s_free(t_stack **head)
{
	t_stack	*tmp;

	while (*head != NULL)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}

void	printerror(t_stack *a)
{
	s_free(&a);
	write(2, "Error\n", 7);
	exit(EXIT_FAILURE);
}

int	stacklen(t_stack *a)
{
	t_stack	*tmp;
	int		counter;

	counter = 0;
	tmp = a;
	while (tmp)
	{
		tmp = tmp->next;
		counter++;
	}
	return (counter);
}

int	ft_2dfree(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
	return (0);
}

int	ft_2darrlen(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i - 1);
}
