/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:47:58 by motroian          #+#    #+#             */
/*   Updated: 2023/02/10 20:34:04 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new->next = *lst;
	*lst = new;
}

void	rotate_a(t_list **pile_a)
{
	t_list	*tmp;

	if (!(*pile_a))
		return ;
	tmp = ft_lstlast((*pile_a));
	tmp->next = (*pile_a);
	(*pile_a) = (*pile_a)->next;
	tmp->next->next = NULL;
	ft_printf("ra\n");
}

void	rotate_b(t_list **pile_b)
{
	t_list	*tmp;

	if (!(*pile_b))
		return ;
	tmp = ft_lstlast((*pile_b));
	tmp->next = (*pile_b);
	(*pile_b) = (*pile_b)->next;
	tmp->next->next = NULL;
	ft_printf("rb\n");
}

void	swap_a(t_data *data)
{
	t_list	*tmp;

	tmp = data->pile_a;
	data->pile_a = data->pile_a->next;
	tmp->next = data->pile_a->next;
	data->pile_a->next = tmp;
	data->nb++;
	ft_printf("sa\n");
}

void	swap_b(t_data *data)
{
	t_list	*tmp;

	tmp = data->pile_b;
	data->pile_b = data->pile_b->next;
	tmp->next = data->pile_b->next;
	data->pile_b->next = tmp;
	data->nb++;
	ft_printf("sb\n");
}
