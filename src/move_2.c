/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 07:29:51 by motroian          #+#    #+#             */
/*   Updated: 2023/02/16 23:45:05 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_bb(t_list **pile_b)
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

void	reverse_aa(t_list **pile_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*pile_a))
		return ;
	tmp = ft_lstlast((*pile_a));
	tmp2 = (*pile_a);
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = (*pile_a);
	(*pile_a) = tmp;
}

void	rotate_bb(t_list **pile_b)
{
	t_list	*tmp;

	if (!(*pile_b))
		return ;
	tmp = ft_lstlast((*pile_b));
	tmp->next = (*pile_b);
	(*pile_b) = (*pile_b)->next;
	tmp->next->next = NULL;
}

void	rotate_aa(t_list **pile_a)
{
	t_list	*tmp;

	if (!(*pile_a))
		return ;
	tmp = ft_lstlast((*pile_a));
	tmp->next = (*pile_a);
	(*pile_a) = (*pile_a)->next;
	tmp->next->next = NULL;
}

void	rrr(t_data *data)
{
	if (data->pile_a || data->pile_b)
		return ;
	reverse_aa(&data->pile_a);
	reverse_bb(&data->pile_b);
	ft_printf("rrr\n");
}
