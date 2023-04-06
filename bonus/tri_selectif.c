/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_selectif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 07:02:29 by motroian          #+#    #+#             */
/*   Updated: 2023/02/13 22:42:54 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexation(long int *tab, t_data *data, int size)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = data->pile_a;
	while (tmp)
	{
		while (i < size)
		{
			if (tab[i] == tmp->valeur)
				tmp->index = i;
			i++;
		}
		i = 0;
		tmp = tmp->next;
	}
}

int	ft_mediane(long int *tab, t_data *data, int size)
{
	int	i;
	int	mediane;

	if (size % 2 == 0)
		data->mediane = tab[size / 2];
	else if (size % 2 != 0)
	{
		i = size / 2;
		data->mediane5 = tab[i];
		i++;
		data->mediane = tab[i];
	}
	mediane = data->mediane;
	return (mediane);
}

long int	*ft_sort_int_tab(long int *tab, int size, t_data *data)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i++;
	}
	data->top = tab[size - 1];
	ft_mediane(tab, data, size);
	return (tab);
}
