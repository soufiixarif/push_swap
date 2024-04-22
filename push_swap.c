/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:12:25 by sarif             #+#    #+#             */
/*   Updated: 2024/04/21 20:17:51 by sarif            ###   ########.fr       */
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
			exit(EXIT_FAILURE);
		pushtostack(a, ft_atoi(av[i]));
		i--;
	}
	ft_2dfree(av);
	set_position(*a);
}

void	pushsecondcase(t_stack **a, int ac, char **av)
{
	int	i;

	i = 0;
	i = ac - 1;
	while (i > 0)
	{
		if (!checkvalidity(av[i]))
			exit(EXIT_FAILURE);
		pushtostack (a, ft_atoi(av[i]));
		i--;
	}
	set_position(*a);
}

void	pushtostack(t_stack **head, int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (*head != NULL)
		(*head)->prev = new_node;
	new_node->n = data;
	new_node->next = *head;
	new_node->prev = NULL;
	(*head) = new_node;
}

void	f(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || !av[1][0])
		return (1);
	if (ac == 2)
		pushfirstcase(&a, av);
	else if (ac > 2)
		pushsecondcase(&a, ac, av);
	checkdouble(a);
	sorting(&a, &b);
	s_free(&a);
}
