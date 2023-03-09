/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motroian <motroian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:43:22 by motroian          #+#    #+#             */
/*   Updated: 2023/01/16 19:26:13 by motroian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
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

void	aff_list(t_list *lst)
{
	while (lst != NULL)
	{
		printf("===%d\n", lst->valeur);
		lst = lst->next;
	}
}

void	ft_add(t_data *data)
{
	int	i;
	t_list	*temp;


	i = 0;
	data->pile_a = ft_lstnew(data->tab[0], 0);
	temp = data->pile_a;
	while (++i < data->len)
		ft_lstadd_back(&data->pile_a, ft_lstnew(data->tab[i], i));
	aff_list(temp);
}
