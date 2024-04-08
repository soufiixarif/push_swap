/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:12:25 by sarif             #+#    #+#             */
/*   Updated: 2024/04/07 17:48:53 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pushtostack(mystack **head,int data)
{
    mystack *new_node = (mystack *)malloc(sizeof(mystack));

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
    mystack *a = NULL;
    mystack *b = NULL;
    int i = 0;

    atexit(f);
    if (ac == 1 || !av[1][0])
        return(1);
    if (ac == 2)
    {
        av = ft_split(av[1], ' ');
        while(av[i])
        {
            if(!checkvalidity(av[i]))
                exit(EXIT_FAILURE);
            pushtostack(&a,ft_atoi(av[i]));
            i++;
        }  
    }
    else if (ac > 2)
    {
        i = 1;
        while(av[i])
        {
            if(!checkvalidity(av[i]))
                exit(EXIT_FAILURE);
            pushtostack(&a,ft_atoi(av[i]));
            i++;
        }
    }
    // mystack *tmp;
    // tmp = a;
    // printf("========= before sorting===========\n");
    // while(tmp)
    // {
    //     printf("%d\n",tmp->n);
    //     tmp = tmp->next;
    // }
    sorting(&a,&b);
    s_free(a);
    // printf("========= after sorting===========\n");
    // tmp = a;
    // while(tmp)
    // {
    //     printf("%d\n",tmp->n);
    //     tmp = tmp->next;
    // }
}