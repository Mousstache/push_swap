/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 07:29:51 by motroian          #+#    #+#             */
/*   Updated: 2023/02/04 16:33:07 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_list **pile_a)
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
	ft_printf("rra\n");
}

void	reverse_b(t_list **pile_b)
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
	ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	reverse_a(&data->pile_a);
	reverse_b(&data->pile_b);
}

void	rr(t_data *data)
{
	rotate_a(&data->pile_a);
	rotate_b(&data->pile_b);
}
