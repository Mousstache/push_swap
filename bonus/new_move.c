/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 21:07:16 by motroian          #+#    #+#             */
/*   Updated: 2023/02/15 21:09:51 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_rotate_a(t_list **pile_a)
{
	t_list	*tmp;

	if (!(*pile_a))
		return ;
	tmp = ft_lstlast((*pile_a));
	tmp->next = (*pile_a);
	(*pile_a) = (*pile_a)->next;
	tmp->next->next = NULL;
}

void	new_rotate_b(t_list **pile_b)
{
	t_list	*tmp;

	if (!(*pile_b))
		return ;
	tmp = ft_lstlast((*pile_b));
	tmp->next = (*pile_b);
	(*pile_b) = (*pile_b)->next;
	tmp->next->next = NULL;
}

void	new_swap_a(t_data *data)
{
	t_list	*tmp;

	tmp = data->pile_a;
	data->pile_a = data->pile_a->next;
	tmp->next = data->pile_a->next;
	data->pile_a->next = tmp;
	data->nb++;
}

void	new_swap_b(t_data *data)
{
	t_list	*tmp;

	tmp = data->pile_b;
	data->pile_b = data->pile_b->next;
	tmp->next = data->pile_b->next;
	data->pile_b->next = tmp;
	data->nb++;
}
