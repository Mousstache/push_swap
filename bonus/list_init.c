/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:43:22 by motroian          #+#    #+#             */
/*   Updated: 2023/02/11 21:57:23 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int nb, int index)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->valeur = nb;
	lst->index = index;
	lst->next = NULL;
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	size = 0;
	temp = lst;
	if (!lst)
		return (0);
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

void	ft_add(t_data *data)
{
	int	i;

	i = 0;
	data->pile_a = ft_lstnew(data->tab[0], 0);
	while (++i <= data->len)
	{
		ft_lstadd_back(&data->pile_a, ft_lstnew(data->tab[i], i));
	}
}
