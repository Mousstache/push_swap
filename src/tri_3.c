/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:12:10 by motroian          #+#    #+#             */
/*   Updated: 2023/02/04 16:39:22 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_3(t_data *data)
{
	t_list *tmp;

	tmp = data->pile_a;
	if (tmp->valeur > tmp->next->valeur
		&& tmp->next->valeur > tmp->next->next->valeur
		&& tmp->valeur > tmp->next->next->valeur) // 321
	{
		rotate_a(&data->pile_a);
		swap_a(data);
	}
	else if (tmp->valeur > tmp->next->valeur
		&& tmp->next->valeur < tmp->next->next->valeur
		&& tmp->valeur < tmp->next->next->valeur) // 213
		swap_a(data);
	else if (tmp->valeur > tmp->next->valeur
		&& tmp->next->valeur < tmp->next->next->valeur
		&& tmp->valeur > tmp->next->next->valeur) // 312
			rotate_a(&data->pile_a);
	else if (tmp->valeur < tmp->next->valeur
		&& tmp->next->valeur > tmp->next->next->valeur
		&& tmp->valeur < tmp->next->next->valeur) // 132
	{
		reverse_a(&data->pile_a);
		swap_a(data);
	}
	else if (tmp->valeur < tmp->next->valeur
		&& tmp->next->valeur > tmp->next->next->valeur
		&& tmp->valeur > tmp->next->next->valeur) // 231
		reverse_a(&data->pile_a);
}

void	tri_5(t_data *data)
{
	while (data->size_a != 3)
	{
		if (data->pile_a->index < data->mediane - 1)
			push_b(data);
		else
			rotate_a(& data->pile_a);
	}
	tri_3(data);
	if (data->pile_b->valeur < data->pile_b->next->valeur)
		swap_b(data);
	push_a(data);
	push_a(data);
}

long int	*newtab(t_data *data)
{
	long int *tab;
	t_list *temp;
	int i = 0;
	temp = data->pile_a;
	tab = malloc(sizeof(long int) * data->size_a);
	while (temp)
	{
		tab[i++] = temp->valeur;
		temp = temp->next;
	}
	return (tab);
}

void	pre_tri(t_data *data)
{
	long int *tab;
	int mediane = data->mediane;
	
	while (data->size_a != 3)
	{
		if (data->pile_a->valeur >= mediane)
		{
			push_b(data);
			long int *newtabok = newtab(data);
			tab = ft_sort_int_tab(newtabok, data->size_a, data);
			mediane = tab[(data->size_a / 7) * 5];
		}
		else
			rotate_a(& data->pile_a);
	}
	tri_3(data);
}