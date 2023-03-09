/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:47:58 by motroian          #+#    #+#             */
/*   Updated: 2023/01/16 23:06:41 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst)
		new->next = *lst;
	*lst = new;
}

// void	ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	if (lst)
// 	{
// 		(*del)(lst->content);
// 		free(lst);
// 	}
// }

void	swap_a(t_list *pile_a)
{
	t_list *tmp;
	int	i;
	
	i = 0;
	tmp = ft_lstnew(pile_a->next->valeur, pile_a->next->index);
	ft_lstadd_front(&pile_a, tmp);
	// while(i < 2)
	// {
	// 	pile_a = pile_a->next;
	// 	i++;
	// }
	pile_a->next->next = pile_a->next->next->next;
	// free(pile_a->next->next);
	// ft_lstdelone(pile_a);
	aff_list(pile_a);
}