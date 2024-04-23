/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:12:25 by sarif             #+#    #+#             */
/*   Updated: 2024/04/23 21:02:56 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushfirstcase(t_stack **a, char **av)
{
	int	i;

	i = 0;
	av = ft_split(av[1], ' ');
	i = ft_2darrlen(av);
	while (i >= 0)
	{
		if (!checkvalidity(av[i]))
			printerror(*a);
		pushtostack(a, ft_atoi(av[i]));
		i--;
	}
	ft_2dfree(av);
	set_position(*a);
}

void	pushsecondcase(t_stack **a, int ac, char **av)
{
	int		i;
	int		j;
	char	**args;

	i = ac;
	args = NULL;
	while (--i > 0)
	{
		j = ft_countword(av[i], ' ');
		if (!j)
			printerror(*a);
		args = ft_split(av[i], ' ');
		while (--j >= 0)
		{
			if (!checkvalidity(args[j]))
			{
				ft_2dfree(args);
				printerror(*a);
			}
			pushtostack (a, ft_atoi(args[j]));
		}
		ft_2dfree(args);
	}
	set_position(*a);
}

void	pushtostack(t_stack **head, long data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		printerror(*head);
	if (*head != NULL)
		(*head)->prev = new_node;
	new_node->n = data;
	new_node->next = *head;
	new_node->prev = NULL;
	(*head) = new_node;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || !av[1][0])
		return (0);
	if (ac == 2)
		pushfirstcase(&a, av);
	else if (ac > 2)
		pushsecondcase(&a, ac, av);
	checkdouble(a);
	if (!is_sorted(&a))
		sorting(&a, &b);
	s_free(&a);
}
