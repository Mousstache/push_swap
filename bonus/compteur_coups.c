/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compteur_coups.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:00:35 by motroian          #+#    #+#             */
/*   Updated: 2023/02/11 22:21:17 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_data *data)
{
	t_list	*temp;
	int		comp;

	comp = data->pile_a->valeur;
	temp = data->pile_a;
	while (temp)
	{
		if (temp -> valeur < comp)
		{
			data->index_min = temp->pos;
			comp = temp->valeur;
		}
		temp = temp -> next;
	}
	return (comp);
}

int	findindex_min(t_data *data)
{
	t_list	*temp;
	int		min;
	int		i;

	i = 0;
	min = find_min(data);
	temp = data->pile_a;
	while (temp->valeur != min)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}

void	pushmintotop(t_data *data)
{
	int	min;
	int	pos_min;

	min = find_min(data);
	pos_min = findindex_min(data);
	if (pos_min <= ft_lstsize(data->pile_a) / 2)
	{
		while (data->pile_a->valeur > min)
		{
			rotate_a(&data->pile_a);
		}
	}
	else
	{
		while (data->pile_a->valeur > min)
		{
			reverse_a(&data->pile_a);
		}
	}
}
