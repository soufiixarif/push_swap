/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:09:58 by sarif             #+#    #+#             */
/*   Updated: 2024/04/13 16:15:35 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	fprintf(stderr, "khroj f7alek");
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
		counter++;
		tmp = tmp->next;
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
