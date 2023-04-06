/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:07:32 by motroian          #+#    #+#             */
/*   Updated: 2023/02/16 23:02:22 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		if (str[1] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_range(long int *tab, int size)
{
	int	i;

	i = 0;
	while (i <= size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlentab(char **av)
{
	int		i;
	int		j;
	int		k;
	char	**argv;

	i = 1;
	k = 0;
	while (av[i])
	{
		argv = ft_split(av[i], ' ');
		if (!argv)
			return (0);
		j = 0;
		while (argv[j])
		{
			j++;
			k++;
		}
		i++;
		free_all(argv);
	}
	return (k);
}

char	**decoupe_arg(char **av, int i)
{
	int		j;
	int		k;
	char	**argv;
	char	**tab;

	k = 0;
	tab = ft_calloc(sizeof(char *), ft_strlentab(av) + 1);
	if (!tab)
		return (NULL);
	while (av[++i])
	{
		j = 0;
		argv = ft_split(av[i], ' ');
		if (!argv || !*argv)
			return (free_all(tab), free_all(argv), NULL);
		while (argv[j])
		{
			tab[k] = ft_strdup(argv[j++]);
			if (!tab[k++])
				return (free_all(tab), free_all(argv), NULL);
		}
		free_all(argv);
	}
	return (tab);
}
