/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:04:27 by sarif             #+#    #+#             */
/*   Updated: 2024/04/21 06:30:48 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct stack_s
{
	int				n;
	int				position;
	int				idx;
	int				check;
	struct stack_s	*prev;
	struct stack_s	*next;
}	t_stack;

typedef struct range_s
{
	int	min;
	int	max;
}	t_range;

void	pushtostack(t_stack **head, int data);
void	printerror(t_stack *a);
int		checkvalidity(char *s);
void	sorting(t_stack **a, t_stack **b);
int		stacklen(t_stack *a);
void	sortingthree(t_stack **a);
void	sortingfive(t_stack **a, t_stack **b);
int		max(t_stack **a);
int		min(t_stack *a);
long	get_min(t_stack *a);
void	indexing(t_stack *a);
void	checkdouble(t_stack *a);
void	set_position(t_stack *a);
void	make_it_top(t_stack **a, t_stack **b, int pos, int min);
int		check_if_it_top(t_stack **a, int min);
int		nb_content(char *s, int len, int i);
void	chunkpush(t_stack **a, t_stack **b, int min, int max);
void	lastchunkpush(t_stack **a, t_stack **b, int min, int max);
int		max_in_buttom(t_stack **a, int max);
int		buttom_is_available(t_stack **a);
void	makeorder(t_stack **a, t_stack **b);
void	make_correct_top(t_stack **a, t_stack **b);
int		lastidx(t_stack *a);
int		optimisation(t_stack **a, int max);
void	makeorder2(t_stack **a, t_stack **b);
int		close_to_top(t_stack **b, int index);

// void	orderopti(t_stack **a, t_stack **b);


/* actions */
void	sa(t_stack **a, int checker);
void	sb(t_stack **b, int checker);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int checker);
void	rb(t_stack **b, int checker);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int checker);
void	rrb(t_stack **b, int checker);
void	rrr(t_stack **a, t_stack **b);

/*libft functions*/
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);

void	s_free(t_stack **head);
int		ft_2dfree(char **s);
int		ft_2darrlen(char **av);

#endif