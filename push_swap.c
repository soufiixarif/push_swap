/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:12:25 by sarif             #+#    #+#             */
/*   Updated: 2024/04/13 00:30:07 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushtostack(t_stack **head, int data)
{
	t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));

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
	int		i = 0;
    (void)b;

	// atexit(f);
	if (ac == 1 || !av[1][0])
		return (1);
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		while (av[i])
		{
			if (!checkvalidity(av[i]))
				exit(EXIT_FAILURE);
			pushtostack(&a, ft_atoi(av[i]));
			i++;
		}
		ft_2dfree(av);
        set_position(a);
	}
	else if (ac > 2)
	{
		i = 1;
		while (av[i])
		{
			if (!checkvalidity(av[i]))
				exit(EXIT_FAILURE);
			pushtostack (&a, ft_atoi(av[i]));
			i++;
		}
        set_position(a);
	}
	checkdouble(a);
    t_stack *tmp;
    printf("==========before==========\n");
    tmp = a;
    while (tmp)
    {
        printf("%d\n",tmp->n);
        tmp = tmp->next;
    }
    printf("==========after==========\n");
	sorting(&a, &b);
    tmp = a;
    while (tmp)
    {
        printf("%d\n",tmp->n);
        tmp = tmp->next;
    }
	s_free(&a);
}
