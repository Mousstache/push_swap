/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_move3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:43:42 by motroian          #+#    #+#             */
/*   Updated: 2023/02/16 20:20:08 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	new_push_b(t_data *data)
{
	t_list	*tmp;

	if (!data->pile_a)
		return ;
	tmp = data->pile_a;
	data->pile_a = data->pile_a->next;
	tmp->next = data->pile_b;
	data->pile_b = tmp;
	data->size_a--;
	data->size_b++;
	data->nb++;
}

void	new_push_a(t_data *data)
{
	t_list	*tmp;

	if (!data->pile_b)
		return ;
	tmp = data->pile_b;
	data->pile_b = data->pile_b->next;
	tmp->next = data->pile_a;
	data->pile_a = tmp;
	data->size_b--;
	data->size_a++;
	data->nb++;
}

void	new_reverse_a(t_list **pile_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*pile_a) || (*pile_a)->next == NULL)
		return ;
	tmp = ft_lstlast((*pile_a));
	tmp2 = (*pile_a);
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = (*pile_a);
	(*pile_a) = tmp;
}

void	new_reverse_b(t_list **pile_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*pile_b) || (*pile_b)->next == NULL)
		return ;
	tmp = ft_lstlast((*pile_b));
	tmp2 = (*pile_b);
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = (*pile_b);
	(*pile_b) = tmp;
}

void	new_rr(t_data *data)
{
	if (!data->pile_a || !data->pile_b)
		return ;
	new_rotate_a(&data->pile_a);
	new_rotate_b(&data->pile_b);
}
