/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   daron.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:50:23 by motroian          #+#    #+#             */
/*   Updated: 2023/02/13 00:12:52 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_daron(t_data *data)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		save;
	int		pos_daron;

	tmp_b = data->pile_b;
	while (tmp_b)
	{
		save = 2147483647;
		tmp_a = data->pile_a;
		while (tmp_a)
		{
			if (tmp_a->valeur > tmp_b->valeur && save >= tmp_a->valeur)
			{
				save = tmp_a->valeur;
				pos_daron = tmp_a->pos;
			}
			tmp_a = tmp_a->next;
		}
		if (save == 2147483647)
			tmp_b->daron = val_min(data);
		else
			tmp_b->daron = pos_daron;
		tmp_b = tmp_b->next;
	}
}

void	ft_price(t_data *data)
{
	t_list	*tmp;
	int		i;
	int		coup;
	int		len;

	tmp = data->pile_b;
	len = ft_lstsize(data->pile_b);
	while (tmp)
	{
		coup = 0;
		if (tmp->pos <= len / 2)
		{
			i = tmp->pos;
			coup = i;
		}
		else
			coup += (len - 1) - tmp->pos;
		if (tmp->daron <= ft_lstsize(data->pile_a) / 2)
			coup += tmp->daron;
		else
			coup += (ft_lstsize(data->pile_a) - 1) - tmp->daron;
		tmp->coup = coup;
		tmp = tmp->next;
	}
}

int	pos_coup_max(t_data *data)
{
	t_list	*tmp;
	int		pos_max;
	int		comp;

	pos_max = 0;
	tmp = data->pile_b;
	comp = data->pile_b->coup;
	while (tmp)
	{
		if (tmp->coup > comp)
		{
			comp = tmp->coup;
			pos_max = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (pos_max);
}

int	find_best(t_data *data)
{
	t_list	*tmp;
	int		best;
	int		comp;

	tmp = data->pile_b;
	comp = data->pile_b->coup;
	best = 0;
	while (tmp)
	{
		if (tmp->coup < comp)
		{
			comp = tmp->coup;
			best = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (best);
}

void	execute(t_data *data)
{
	t_list	*tmp;
	int		best;

	tmp = data->pile_b;
	best = find_best(data);
	while (tmp->next && tmp->pos != best)
		tmp = tmp->next;
	put_top_b(data, tmp->pos);
	put_top_a(data, tmp->daron);
	push_a(data);
}
