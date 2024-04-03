/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:04:27 by sarif             #+#    #+#             */
/*   Updated: 2024/04/02 18:13:01 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} mystack;

typedef struct s_data
{
    char **args;
} t_data;

void	pushtostack(mystack **head, int data);
void	printerror(mystack *a);
int		checkvalidity(char *s);

/* actions */
void sa(mystack **a);
void sb(mystack **b);
void ss(mystack **a,mystack **b);
void pa(mystack **a, mystack **b);
void pb(mystack **a, mystack **b);
void ra(mystack **a);
void rb(mystack **b);
void rr(mystack **a, mystack **b);
void rra(mystack **a);
void rrb(mystack **b);
void rrr(mystack **a, mystack **b);


/*libft functions*/
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);

extern mystack *a;
extern mystack *b;

#endif