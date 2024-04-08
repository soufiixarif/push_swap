/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarif <sarif@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 01:32:10 by sarif             #+#    #+#             */
/*   Updated: 2024/04/08 21:57:05 by sarif            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countword(char const *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
			counter++;
		while (str[i] != c && str[i])
			i++;
	}
	return (counter);
}

static void	*ft_freestr(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	return (free(str), str = NULL, NULL);
}

static char	**ft_allocstr(char **strings, char *s, char c)
{
	int		count;
	int		j;
	int		i;

	count = ft_countword(s, c);
	j = 0;
	while (j < count)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] != c && s[i] != '\0')
			i++;
		strings[j] = (char *)ft_calloc((i + 1), sizeof (char));
		if (!strings[j])
			return (ft_freestr(strings, j));
		ft_strlcpy(strings[j], (s), (i + 1));
		j++;
		s = s + i;
	}
	strings[j] = NULL;
	return (strings);
}

char	**ft_split(char *s, char c)
{
	char	**strings;
	int		count;

	if (!s)
		return (NULL);
	count = ft_countword(s, c);
	strings = (char **)ft_calloc((count + 1), sizeof(char *));
	if (!strings)
		return (0);
	return (ft_allocstr(strings, s, c));
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	size_t	i;

	i = count * size;
	if (size && i / size != count)
		return (NULL);
	s = malloc(count * size);
	if (!s)
		exit(2);
	ft_bzero(s, count * size);
	return (s);
}
