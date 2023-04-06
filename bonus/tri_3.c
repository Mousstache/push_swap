/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 18:12:10 by motroian          #+#    #+#             */
/*   Updated: 2023/02/13 23:04:32 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tri_3(t_data *data)
{
	t_list	*tmp;
	int		a;
	int		b;
	int		c;

	tmp = data->pile_a;
	a = tmp->valeur;
	b = tmp->next->valeur;
	c = tmp->next->next->valeur;
	if (a > b && b > c && a > c)
	{
		rotate_a(&data->pile_a);
		swap_a(data);
	}
	else if (a > b && b < c && a < c)
		swap_a(data);
	else if (a > b && b < c && a > c)
		rotate_a(&data->pile_a);
	else if (a < b && b > c && a < c)
	{
		reverse_a(&data->pile_a);
		swap_a(data);
	}
	else if (a < b && b > c && a > c)
		reverse_a(&data->pile_a);
}

void	tri_5(t_data *data)
{
	while (data->size_a != 3)
	{
		if (data->pile_a->valeur < data->mediane5)
			push_b(data);
		else
			rotate_a(& data->pile_a);
	}
	tri_3(data);
	if (data->pile_b->valeur < data->pile_b->next->valeur)
		swap_b(data);
	push_a(data);
	push_a(data);
	pushmintotop(data);
}

long int	*newtab(t_data *data, int *size)
{
	long int	*tab;
	t_list		*temp;
	int			i;

	i = 0;
	temp = data->pile_a;
	*size = ft_lstsize(data->pile_a);
	tab = malloc(sizeof(long int) * (*size));
	while (temp)
	{
		tab[i++] = temp->valeur;
		temp = temp->next;
	}
	return (tab);
}

void	pre_tri(t_data *data)
{
	long int	*new_tab;
	int			mediane;
	int			size;

	mediane = data->mediane;
	while (data->size_a > 3)
	{
		if (data->pile_a->valeur <= mediane)
		{
			push_b(data);
			new_tab = newtab(data, &size);
			ft_sort_int_tab(new_tab, size, data);
			mediane = new_tab[size / 2 - 1];
			free(new_tab);
		}
		else
			rotate_a(&data->pile_a);
	}
	tri_3(data);
}
