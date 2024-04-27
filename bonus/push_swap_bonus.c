/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:12:25 by sarif             #+#    #+#             */
/*   Updated: 2024/04/27 04:16:24 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	takedecision(t_stack **a, t_stack **b)
{
	if (is_sorted(*a) && stacklen(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	s_free(a);
	s_free(b);
	exit(EXIT_SUCCESS);
}

void	readfrominput(t_stack **a, t_stack **b)
{
	char	*action;

	action = get_next_line(0);
	if (!action)
		takedecision(a, b);
	while (action)
	{
		executeaction(action, a, b);
		free(action);
		action = get_next_line(0);
	}
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
	else if (ac >= 2)
		pushsecondcase(&a, ac, av);
	checkdouble(a);
	readfrominput(&a, &b);
	takedecision(&a, &b);
	s_free(&a);
	s_free(&b);
}
