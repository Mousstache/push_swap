/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 07:29:19 by motroian          #+#    #+#             */
/*   Updated: 2023/02/14 16:10:33 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *str)
{
	int			a;
	int			b;
	long int	c;

	a = 0;
	b = 0;
	c = 0;
	while ((str[a] >= 9 && str[a] <= 13) || (str[a] == 32))
		a++;
	while (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			b++;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		c = c * 10 + (str[a] - '0');
		a++;
	}
	if (!(b % 2 == 0))
		return (c * -1);
	return (c);
}

int	check_double(long int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(char *str)
{
	int			a;
	int			b;
	long int	c;

	a = 0;
	b = 1;
	c = 0;
	while ((str[a] >= 9 && str[a] <= 13) || (str[a] == 32))
		a++;
	while (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			b *= (-1);
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		c = c * 10 + (str[a] - '0');
		if (c * b < INT_MIN || c * b > INT_MAX)
			return (0);
		a++;
	}
	return (1);
}

void	aff_list(t_list *lst)
{
	int		i;
	t_list	*temp;

	if (!lst)
		return ;
	i = 0;
	temp = lst;
	while (temp)
	{
		ft_printf("%d ===%d\n", i, temp->valeur);
		i++;
		temp = temp->next;
	}
}
