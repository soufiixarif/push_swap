/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkvalidity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:15:44 by sarif             #+#    #+#             */
/*   Updated: 2024/04/23 20:57:02 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_content(char *s, int len, int i)
{
	int	j;

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

int	checkvalidity(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
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
	if (!nb_content(s, len, i))
		return (0);
	return (1);
}

void	checkdouble(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		if (a->n < -2147483648 || a->n > 2147483647)
			printerror(a);
		tmp = a->next;
		while (tmp)
		{
			if (a->n == tmp->n)
				printerror(a);
			tmp = tmp->next;
		}
		a = a->next;
	}
}
