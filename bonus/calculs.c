/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:08:06 by motroian          #+#    #+#             */
/*   Updated: 2023/02/13 19:20:56 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	val_max(t_data *data)
{
	t_list	*tmp;
	int		max;

	tmp = data->pile_a;
	max = tmp->valeur;
	while (tmp)
	{
		if (max < tmp->valeur)
		{
			max = tmp->valeur;
		}
		tmp = tmp->next;
	}
	return (max);
}

int	val_min(t_data *data)
{
	t_list	*tmp;
	int		max;

	tmp = data->pile_a;
	max = tmp->valeur;
	while (tmp)
	{
		if (max > tmp->valeur)
		{
			max = tmp->valeur;
		}
		tmp = tmp->next;
	}
	return (max);
}

void	put_top_b(t_data *data, int pos)
{
	int	len;

	len = ft_lstsize(data->pile_b);
	while (pos != data->pile_b->pos)
	{
		if (pos <= len / 2)
			rotate_b(&data->pile_b);
		else
			reverse_b(&data->pile_b);
	}
}

void	put_top_a(t_data *data, int pos)
{
	int	len;

	len = ft_lstsize(data->pile_a);
	while (pos != data->pile_a->pos)
	{
		if (pos <= len / 2)
			rotate_a(&data->pile_a);
		else
		{
			reverse_a(&data->pile_a);
		}
	}
}

void	get_pos(t_data *data)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (!data->pile_b)
		return ;
	tmp = data->pile_b;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
	i = 0;
	tmp = data->pile_a;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}
