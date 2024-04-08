/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:09:58 by sarif             #+#    #+#             */
/*   Updated: 2024/04/07 17:50:00 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

int checkvalidity(char *s)
{
	int i = 0;
	int len = strlen(s);
	int j;

	len--;
	while(s[i] == 32 || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return(0);
	while(s[len] == 32 || (s[len] == '\t' && len >= 0))
	{
		if(s[len] == 32 || s[len] == '\t')
			len--;
		else
			break;
	}
	j = i;
	while(s[i] && i <= len)
	{
		if (i == j && (s[j] == '-' || s[j] == '+'))
		{
			i++;
			if (s[i] == 32 || s[i] == '\t' || s[i] == '\0')
				return(0);
			continue;
		}
		else if (s[i] >= '0' && s[i++] <= '9')
			continue;
		else
			return(0);
		i++;
	}
	return(1);
}

void s_free(mystack *head)
{
	mystack *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}
void printerror(mystack *a)
{
    // s_free(a);
    (void)a;
    fprintf(stderr,"khroj t9awed");
    exit(EXIT_FAILURE);
}

int stacklen(mystack **a)
{
	mystack *tmp;
	int counter;

	counter = 0;
	tmp = *a;
	while(tmp)
	{
		counter++;
		tmp = tmp->next;
	}
	return(counter);
}
