/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:04:27 by sarif             #+#    #+#             */
/*   Updated: 2024/04/24 20:24:25 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "Get_next_line/get_next_line.h"

typedef struct stack_s
{
	long			n;
	struct stack_s	*prev;
	struct stack_s	*next;
}	t_stack;

void	pushtostack(t_stack **head, long data);
void	printerror(t_stack *a);
int		checkvalidity(char *s);
int		stacklen(t_stack *a);
void	checkdouble(t_stack *a);
int		check_if_it_top(t_stack **a, int min);
int		nb_content(char *s, int len, int i);
int		is_sorted(t_stack *a);
void	pushsecondcase(t_stack **a, int ac, char **av);

//bonus
void	readfrominput(t_stack *a, t_stack *b);
void	takedecision(t_stack *a, t_stack *b);
void	executeaction(char *action, t_stack **a, t_stack **b);
void	exitprogramme(t_stack *a, t_stack *b);

/* actions */
void	sa(t_stack **a, int checker);
void	sb(t_stack **b, int checker);
void	ss(t_stack **a, t_stack **b, int checker);
void	pa(t_stack **a, t_stack **b, int checker);
void	pb(t_stack **a, t_stack **b, int checker);
void	ra(t_stack **a, int checker);
void	rb(t_stack **b, int checker);
void	rr(t_stack **a, t_stack **b, int checker);
void	rra(t_stack **a, int checker);
void	rrb(t_stack **b, int checker);
void	rrr(t_stack **a, t_stack **b, int checker);

/*libft functions*/
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
int		ft_strcmp(char *s1, char *s2);
// size_t	ft_strlen(char *str);
long	ft_atoi(const char *str);
int		ft_countword(char const *str, char c);

void	s_free(t_stack **head);
int		ft_2dfree(char **s);
int		ft_2darrlen(char **av);

#endif