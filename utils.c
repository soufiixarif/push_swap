/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:09:58 by sarif             #+#    #+#             */
/*   Updated: 2024/04/12 23:37:11 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int	checkvalidity(char *s)
{
	int	i = 0;
	int	len = strlen(s);
	int	j;

	len--;
	while (s[i] == 32 || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[len] == 32 || (s[len] == '\t' && len >= 0))
	{
		if (s[len] == 32 || s[len] == '\t')
			len--;
		else
			break ;
	}
	j = i;
	while (s[i] && i <= len)
	{
		if (i == j && (s[j] == '-' || s[j] == '+'))
		{
			i++;
			if (s[i] == 32 || s[i] == '\t' || s[i] == '\0')
				return (0);
			continue ;
		}
		else if (s[i] >= '0' && s[i++] <= '9')
			continue ;
		else
			return (0);
		i++;
	}
	return (1);
}

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
