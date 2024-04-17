/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:12:25 by sarif             #+#    #+#             */
/*   Updated: 2024/04/17 01:57:11 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void f()
{
	system("leaks push_swap");
}
int main(int ac, char **av)
{
	t_stack	*a = NULL;
	t_stack	*b = NULL;
	int		i;

	// atexit(f);
	if (ac == 1 || !av[1][0])
		return (1);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = ft_2darrlen(av);
		printf("%d\n",i);
		while (i >= 0)
		{
			if (!checkvalidity(av[i]))
				exit(EXIT_FAILURE);
			pushtostack(&a, ft_atoi(av[i]));
			i--;
		}
		ft_2dfree(av);
		set_position(a);
	}
	else if (ac > 2)
	{
		i = ac - 1;
		while (i > 0)
		{
			if (!checkvalidity(av[i]))
				exit(EXIT_FAILURE);
			pushtostack (&a, ft_atoi(av[i]));
			i--;
		}
		set_position(a);
	}
	checkdouble(a);
	indexing(a);
	// t_stack *tmp;
	// printf("==========before==========\n");
	// tmp = a;
	// while (tmp)
	// {
	// 	printf("index %d o number %d\n",tmp->idx,tmp->n);
	// 	tmp = tmp->next;
	// }
	// printf("==========after==========\n");
	sorting(&a, &b);
	// printf("====== STACK A ======\n");
	// tmp = a;
	// while (tmp)
	// {
	// 	printf("index %d o number %d\n",tmp->idx,tmp->n);
	// 	tmp = tmp->next;
	// }
	// printf("====== STACK B ======\n");
	// tmp = b;
	// while (tmp)
	// {
	// 	printf("index %d o number %d\n",tmp->idx,tmp->n);
	// 	tmp = tmp->next;
	// }
	s_free(&a);
}
