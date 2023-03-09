/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:33:56 by motroian          #+#    #+#             */
/*   Updated: 2023/01/16 19:18:21 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int	check_num(char *str)
{
	int i;
	
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			printf("fou");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_double(long int *tab, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac -1)
	{
		j = i + 1;
		while (j < ac - 1)
		{
			if (tab[i] == tab[j])
			{
				printf("chien");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(long int *tab, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if ((tab[i] > 2147483647) || (tab[i] < -2147483648))
		{
			printf("batard");
			return (0);
		}
		i++;
	}
	return (1);
}

int	parsing(char **str,int ac, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	data->tab = malloc(sizeof(long int) * ac);
	if (!data->tab)
		return (0);
	while (i < ac)
	{
		if (check_num(str[i]) == 0)
			return (0);
		data->tab[j] = ft_atoi(str[i]);
		i++;
		j++;
	}
	if (check_int(data->tab, ac) == 0)
		return (0);
	if (ac > 2)
		if (check_double(data->tab, ac) == 0)
			return (0);
	return (1);
}

// int	push_swap(char**str, int ac, t_list *list)
// {
// 	if (parsing(str, ac, list) == 0)
// 		return (0);
// 	return (1);
// }

int	main(int ac, char **av)
{
	t_data data;
	data.len = ac - 1;
	
	
	(void)ac;
	if (ac > 1)
	{
		printf("parsing == %d\n", parsing(av, ac, &data));
		ft_add(&data);
		swap_a(data.pile_a);
	}	
	return (0);
}
